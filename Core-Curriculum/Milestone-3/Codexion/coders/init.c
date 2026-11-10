/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:17 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdlib.h>
#include <string.h>

static int	init_one_dongle(t_dongle *dongle)
{
	memset(dongle, 0, sizeof(t_dongle));
	dongle->queue.items = malloc(sizeof(t_request *) * 16);
	if (!dongle->queue.items)
		return (0);
	dongle->queue.capacity = 16;
	if (pthread_mutex_init(&dongle->mutex, NULL) != 0)
	{
		free(dongle->queue.items);
		return (0);
	}
	if (pthread_cond_init(&dongle->cond, NULL) != 0)
	{
		pthread_mutex_destroy(&dongle->mutex);
		free(dongle->queue.items);
		return (0);
	}
	return (1);
}

static int	init_dongles(t_simulation *simulation, t_config *config)
{
	int	index;

	index = 0;
	while (index < config->coders_count)
	{
		if (!init_one_dongle(&simulation->dongles[index]))
			return (0);
		simulation->initialized_dongles++;
		index++;
	}
	return (1);
}

static int	init_coders(t_simulation *simulation, t_config *config)
{
	int		index;
	t_coder	*coder;

	index = 0;
	while (index < config->coders_count)
	{
		coder = &simulation->coders[index];
		memset(coder, 0, sizeof(t_coder));
		coder->id = index + 1;
		coder->simulation = simulation;
		coder->left = &simulation->dongles[index];
		coder->right = &simulation->dongles[
			(index + 1) % config->coders_count];
		coder->last_compile_start = simulation->start_ms;
		if (pthread_mutex_init(&coder->mutex, NULL) != 0)
			return (0);
		simulation->initialized_coders++;
		index++;
	}
	return (1);
}

int	init_simulation(t_simulation *simulation, t_config *config)
{
	memset(simulation, 0, sizeof(*simulation));
	copy_config(&simulation->config, config);
	simulation->start_ms = current_time_ms();
	simulation->dongles = malloc(sizeof(t_dongle) * config->coders_count);
	simulation->coders = malloc(sizeof(t_coder) * config->coders_count);
	if (!simulation->dongles || !simulation->coders)
		return (0);
	if (pthread_mutex_init(&simulation->state_mutex, NULL) != 0)
		return (0);
	simulation->initialized_state = 1;
	if (pthread_cond_init(&simulation->state_cond, NULL) != 0)
		return (0);
	simulation->initialized_state = 2;
	if (pthread_mutex_init(&simulation->log_mutex, NULL) != 0)
		return (0);
	simulation->initialized_state = 3;
	if (!init_dongles(simulation, config))
		return (0);
	return (init_coders(simulation, config));
}

void	destroy_simulation(t_simulation *simulation)
{
	int	index;

	index = 0;
	while (index < simulation->initialized_coders)
		pthread_mutex_destroy(&simulation->coders[index++].mutex);
	index = 0;
	while (index < simulation->initialized_dongles)
	{
		pthread_mutex_destroy(&simulation->dongles[index].mutex);
		pthread_cond_destroy(&simulation->dongles[index].cond);
		free_heap(&simulation->dongles[index++].queue);
	}
	if (simulation->initialized_state >= 1)
		pthread_mutex_destroy(&simulation->state_mutex);
	if (simulation->initialized_state >= 2)
		pthread_cond_destroy(&simulation->state_cond);
	if (simulation->initialized_state >= 3)
		pthread_mutex_destroy(&simulation->log_mutex);
	free(simulation->coders);
	free(simulation->dongles);
}
