/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:20 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

static int	run_threads(t_simulation *simulation, t_config *config)
{
	int	created;
	int	status;

	created = 0;
	status = 1;
	while (status && created < config->coders_count)
	{
		if (pthread_create(&simulation->coders[created].thread, NULL,
				coder_routine, &simulation->coders[created]) != 0)
			status = 0;
		else
			created++;
	}
	if (status && pthread_create(&simulation->monitor, NULL,
			monitor_routine, simulation) != 0)
		status = 0;
	else if (status)
		pthread_join(simulation->monitor, NULL);
	if (!status)
		stop_simulation(simulation);
	while (created > 0)
		pthread_join(simulation->coders[--created].thread, NULL);
	return (status);
}

int	main(int argc, char **argv)
{
	t_config		config;
	t_simulation	simulation;

	if (!parse_arguments(argc, argv, &config))
	{
		fprintf(stderr,
			"Usage: ./codexion coders burnout compile debug refactor ");
		fprintf(stderr, "required cooldown fifo|edf\n");
		return (1);
	}
	if (!init_simulation(&simulation, &config))
	{
		fprintf(stderr, "Initialization failed\n");
		destroy_simulation(&simulation);
		return (1);
	}
	if (!run_threads(&simulation, &config))
	{
		fprintf(stderr, "Thread creation failed\n");
		destroy_simulation(&simulation);
		return (1);
	}
	destroy_simulation(&simulation);
	return (0);
}
