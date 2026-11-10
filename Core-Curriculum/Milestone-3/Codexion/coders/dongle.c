/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:14 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	wait_turn(t_coder *coder, t_dongle *dongle, t_request *request)
{
	long long		now;
	struct timespec	timeout;

	now = current_time_ms();
	if (heap_peek(&dongle->queue) == request && !dongle->held
		&& now >= dongle->available_at)
	{
		heap_pop(&dongle->queue);
		dongle->held = 1;
		pthread_mutex_unlock(&dongle->mutex);
		log_state(coder->simulation, coder->id, "has taken a dongle");
		return (1);
	}
	if (heap_peek(&dongle->queue) == request
		&& (!dongle->held && now < dongle->available_at))
		make_timeout(&timeout, dongle->available_at);
	else
		make_timeout(&timeout, now + 1000);
	pthread_cond_timedwait(&dongle->cond, &dongle->mutex, &timeout);
	return (0);
}

int	acquire_dongle(t_coder *coder, t_dongle *dongle)
{
	t_request	request;
	long long	deadline;

	pthread_mutex_lock(&coder->mutex);
	deadline = coder->last_compile_start
		+ coder->simulation->config.burnout_ms;
	pthread_mutex_unlock(&coder->mutex);
	request.coder = coder;
	request.deadline = deadline;
	pthread_mutex_lock(&dongle->mutex);
	request.sequence = ++dongle->sequence;
	if (!heap_push(&dongle->queue, &request))
	{
		pthread_mutex_unlock(&dongle->mutex);
		return (0);
	}
	while (!simulation_stopped(coder->simulation))
	{
		if (wait_turn(coder, dongle, &request))
			return (1);
	}
	heap_remove(&dongle->queue, &request);
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
	return (0);
}

void	release_dongle(t_coder *coder, t_dongle *dongle)
{
	(void)coder;
	pthread_mutex_lock(&dongle->mutex);
	dongle->held = 0;
	dongle->available_at = current_time_ms()
		+ coder->simulation->config.cooldown_ms;
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}

/* A lone coder owns the only dongle and can never get a second one. */
int	hold_single_dongle(t_coder *coder, t_dongle *dongle)
{
	t_simulation	*simulation;

	simulation = coder->simulation;
	pthread_mutex_lock(&simulation->state_mutex);
	while (!simulation->stopped)
		pthread_cond_wait(&simulation->state_cond, &simulation->state_mutex);
	pthread_mutex_unlock(&simulation->state_mutex);
	release_dongle(coder, dongle);
	return (0);
}

void	wake_dongles(t_simulation *simulation)
{
	int	index;

	index = 0;
	while (index < simulation->config.coders_count)
	{
		pthread_mutex_lock(&simulation->dongles[index].mutex);
		pthread_cond_broadcast(&simulation->dongles[index].cond);
		pthread_mutex_unlock(&simulation->dongles[index].mutex);
		index++;
	}
}
