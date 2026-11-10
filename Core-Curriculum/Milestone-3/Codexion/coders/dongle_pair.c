/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:40:00 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:40:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/* Only a strictly earlier deadline reserves a dongle; ties are first come. */
static int	pair_ready(t_dongle *dongle, t_request *request, long long now)
{
	return (heap_peek(&dongle->queue)->deadline >= request->deadline
		&& !dongle->held && now >= dongle->available_at);
}

static void	wait_blocked(t_dongle *dongle, t_request *request, long long now)
{
	struct timespec	timeout;

	if (heap_peek(&dongle->queue)->deadline >= request->deadline
		&& !dongle->held && now < dongle->available_at)
		make_timeout(&timeout, dongle->available_at);
	else
		make_timeout(&timeout, now + 1000);
	pthread_cond_timedwait(&dongle->cond, &dongle->mutex, &timeout);
}

/* Takes both dongles at once or waits on the one that blocks, holding none. */
static int	try_pair(t_dongle **dongles, t_request *requests)
{
	long long	now;
	int			wait_on;

	pthread_mutex_lock(&dongles[0]->mutex);
	pthread_mutex_lock(&dongles[1]->mutex);
	now = current_time_ms();
	wait_on = pair_ready(dongles[0], &requests[0], now);
	if (wait_on == 1 && pair_ready(dongles[1], &requests[1], now))
	{
		heap_remove(&dongles[0]->queue, &requests[0]);
		heap_remove(&dongles[1]->queue, &requests[1]);
		dongles[0]->held = 1;
		dongles[1]->held = 1;
		pthread_mutex_unlock(&dongles[1]->mutex);
		pthread_mutex_unlock(&dongles[0]->mutex);
		return (1);
	}
	pthread_mutex_unlock(&dongles[!wait_on]->mutex);
	wait_blocked(dongles[wait_on], &requests[wait_on], now);
	pthread_mutex_unlock(&dongles[wait_on]->mutex);
	return (0);
}

static int	enter_queues(t_coder *coder, t_dongle **dongles,
	t_request *requests)
{
	int	index;
	int	pushed;

	pthread_mutex_lock(&coder->mutex);
	requests[0].deadline = coder->last_compile_start
		+ coder->simulation->config.burnout_ms;
	pthread_mutex_unlock(&coder->mutex);
	pthread_mutex_lock(&coder->simulation->state_mutex);
	requests[0].sequence = ++coder->simulation->request_sequence;
	pthread_mutex_unlock(&coder->simulation->state_mutex);
	requests[0].coder = coder;
	requests[1] = requests[0];
	index = 0;
	pushed = 1;
	while (index < 2)
	{
		pthread_mutex_lock(&dongles[index]->mutex);
		if (!heap_push(&dongles[index]->queue, &requests[index]))
			pushed = 0;
		pthread_mutex_unlock(&dongles[index]->mutex);
		index++;
	}
	return (pushed);
}

int	acquire_pair(t_coder *coder, t_dongle *first, t_dongle *second)
{
	t_dongle	*dongles[2];
	t_request	requests[2];
	int			index;
	int			taken;

	dongles[0] = first;
	dongles[1] = second;
	taken = 0;
	if (enter_queues(coder, dongles, requests))
		while (!taken && !simulation_stopped(coder->simulation))
			taken = try_pair(dongles, requests);
	index = -1;
	while (!taken && ++index < 2)
	{
		pthread_mutex_lock(&dongles[index]->mutex);
		heap_remove(&dongles[index]->queue, &requests[index]);
		pthread_cond_broadcast(&dongles[index]->cond);
		pthread_mutex_unlock(&dongles[index]->mutex);
	}
	if (!taken)
		return (0);
	log_state(coder->simulation, coder->id, "has taken a dongle");
	log_state(coder->simulation, coder->id, "has taken a dongle");
	return (1);
}
