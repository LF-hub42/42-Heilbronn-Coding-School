/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:22 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	stop_simulation(t_simulation *simulation)
{
	pthread_mutex_lock(&simulation->state_mutex);
	simulation->stopped = 1;
	pthread_cond_broadcast(&simulation->state_cond);
	pthread_mutex_unlock(&simulation->state_mutex);
	wake_dongles(simulation);
}

static int	all_completed(t_simulation *simulation)
{
	int	index;
	int	complete;

	complete = 1;
	index = 0;
	while (index < simulation->config.coders_count)
	{
		pthread_mutex_lock(&simulation->coders[index].mutex);
		if (simulation->coders[index].compile_count
			< simulation->config.required_compiles)
			complete = 0;
		pthread_mutex_unlock(&simulation->coders[index].mutex);
		index++;
	}
	return (complete);
}

static int	next_burnout(t_simulation *simulation, int *coder_id,
	long long *deadline)
{
	long long	candidate;
	int			index;

	*coder_id = 0;
	*deadline = 0;
	index = 0;
	while (index < simulation->config.coders_count)
	{
		pthread_mutex_lock(&simulation->coders[index].mutex);
		candidate = simulation->coders[index].last_compile_start
			+ simulation->config.burnout_ms;
		if (*coder_id == 0 || candidate < *deadline)
		{
			*coder_id = simulation->coders[index].id;
			*deadline = candidate;
		}
		pthread_mutex_unlock(&simulation->coders[index].mutex);
		index++;
	}
	return (*coder_id != 0);
}

static int	monitor_step(t_simulation *simulation)
{
	int				coder_id;
	long long		deadline;
	long long		now;
	struct timespec	timeout;

	pthread_mutex_lock(&simulation->state_mutex);
	if (all_completed(simulation))
	{
		pthread_mutex_unlock(&simulation->state_mutex);
		stop_simulation(simulation);
		return (1);
	}
	next_burnout(simulation, &coder_id, &deadline);
	now = current_time_ms();
	if (now >= deadline)
	{
		pthread_mutex_unlock(&simulation->state_mutex);
		log_burnout(simulation, coder_id);
		return (1);
	}
	make_timeout(&timeout, deadline);
	pthread_cond_timedwait(&simulation->state_cond,
		&simulation->state_mutex, &timeout);
	pthread_mutex_unlock(&simulation->state_mutex);
	return (0);
}

void	*monitor_routine(void *argument)
{
	t_simulation	*simulation;

	simulation = (t_simulation *)argument;
	while (1)
	{
		pthread_mutex_lock(&simulation->state_mutex);
		if (simulation->stopped)
		{
			pthread_mutex_unlock(&simulation->state_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&simulation->state_mutex);
		if (monitor_step(simulation))
			return (NULL);
	}
}
