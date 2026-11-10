/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:22:56 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	stopped(t_simulation *simulation)
{
	int	value;

	pthread_mutex_lock(&simulation->state_mutex);
	value = simulation->stopped;
	pthread_mutex_unlock(&simulation->state_mutex);
	return (value);
}

static int	take_dongles(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	if (coder->left < coder->right)
	{
		first = coder->left;
		second = coder->right;
	}
	else
	{
		first = coder->right;
		second = coder->left;
	}
	if (first != second && coder->simulation->config.edf)
		return (acquire_pair(coder, first, second));
	if (!acquire_dongle(coder, first))
		return (0);
	if (first == second)
		return (hold_single_dongle(coder, first));
	if (!acquire_dongle(coder, second))
	{
		release_dongle(coder, first);
		return (0);
	}
	return (1);
}

static void	put_dongles(t_coder *coder)
{
	release_dongle(coder, coder->left);
	if (coder->left != coder->right)
		release_dongle(coder, coder->right);
}

static void	compile_once(t_coder *coder, t_simulation *simulation)
{
	pthread_mutex_lock(&coder->mutex);
	coder->last_compile_start = current_time_ms();
	pthread_mutex_unlock(&coder->mutex);
	log_state(simulation, coder->id, "is compiling");
	wait_ms(simulation->config.compile_ms);
	put_dongles(coder);
	pthread_mutex_lock(&coder->mutex);
	coder->compile_count++;
	pthread_mutex_unlock(&coder->mutex);
	pthread_mutex_lock(&simulation->state_mutex);
	pthread_cond_broadcast(&simulation->state_cond);
	pthread_mutex_unlock(&simulation->state_mutex);
}

void	*coder_routine(void *argument)
{
	t_coder			*coder;
	t_simulation	*simulation;

	coder = (t_coder *)argument;
	simulation = coder->simulation;
	while (!stopped(simulation))
	{
		if (!take_dongles(coder))
			break ;
		compile_once(coder, simulation);
		if (stopped(simulation))
			break ;
		log_state(simulation, coder->id, "is debugging");
		wait_ms(simulation->config.debug_ms);
		if (stopped(simulation))
			break ;
		log_state(simulation, coder->id, "is refactoring");
		wait_ms(simulation->config.refactor_ms);
	}
	return (NULL);
}
