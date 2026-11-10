/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:20:00 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <string.h>

static int	parse_positive(const char *text, long long *value)
{
	long long	result;
	int			index;

	if (!text || !text[0])
		return (0);
	result = 0;
	index = 0;
	while (text[index])
	{
		if (text[index] < '0' || text[index] > '9'
			|| result > 2147483647LL / 10)
			return (0);
		result = result * 10 + text[index] - '0';
		if (result > 2147483647LL)
			return (0);
		index++;
	}
	*value = result;
	return (1);
}

int	parse_arguments(int argc, char **argv, t_config *config)
{
	long long	values[7];
	int			index;

	if (argc != 9 || !config)
		return (0);
	index = 0;
	while (index < 7)
	{
		if (!parse_positive(argv[index + 1], &values[index])
			|| (values[index] == 0 && index != 6))
			return (0);
		index++;
	}
	if (strcmp(argv[8], "fifo") != 0 && strcmp(argv[8], "edf") != 0)
		return (0);
	config->coders_count = (int)values[0];
	config->burnout_ms = values[1];
	config->compile_ms = values[2];
	config->debug_ms = values[3];
	config->refactor_ms = values[4];
	config->required_compiles = (int)values[5];
	config->cooldown_ms = values[6];
	config->edf = strcmp(argv[8], "edf") == 0;
	return (1);
}

void	copy_config(t_config *destination, const t_config *source)
{
	destination->coders_count = source->coders_count;
	destination->burnout_ms = source->burnout_ms;
	destination->compile_ms = source->compile_ms;
	destination->debug_ms = source->debug_ms;
	destination->refactor_ms = source->refactor_ms;
	destination->required_compiles = source->required_compiles;
	destination->cooldown_ms = source->cooldown_ms;
	destination->edf = source->edf;
}
