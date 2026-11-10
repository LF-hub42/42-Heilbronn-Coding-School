/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:20 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <unistd.h>

static int	append_number(char *buffer, int length, long long number)
{
	char	digits[32];
	int		digit_count;

	digit_count = 0;
	while (number > 0)
	{
		digits[digit_count++] = '0' + number % 10;
		number /= 10;
	}
	while (digit_count > 0)
		buffer[length++] = digits[--digit_count];
	return (length);
}

static int	format_line(char *buffer, long long timestamp, int id,
	const char *message)
{
	int	length;
	int	index;

	length = 0;
	if (timestamp == 0)
		buffer[length++] = '0';
	length = append_number(buffer, length, timestamp);
	buffer[length++] = ' ';
	length = append_number(buffer, length, id);
	buffer[length++] = ' ';
	index = 0;
	while (message[index])
		buffer[length++] = message[index++];
	buffer[length++] = '\n';
	return (length);
}

static void	log_line(t_simulation *simulation, int id, const char *message,
	int final)
{
	char	buffer[128];
	int		length;
	int		index;
	ssize_t	written;

	pthread_mutex_lock(&simulation->log_mutex);
	length = 0;
	pthread_mutex_lock(&simulation->state_mutex);
	if (!simulation->stopped)
		length = format_line(buffer,
				current_time_ms() - simulation->start_ms, id, message);
	if (final)
		simulation->stopped = 1;
	pthread_mutex_unlock(&simulation->state_mutex);
	index = 0;
	while (index < length)
	{
		written = write(1, buffer + index, length - index);
		if (written <= 0)
			break ;
		index += written;
	}
	pthread_mutex_unlock(&simulation->log_mutex);
}

void	log_state(t_simulation *simulation, int id, const char *message)
{
	log_line(simulation, id, message, 0);
}

void	log_burnout(t_simulation *simulation, int id)
{
	log_line(simulation, id, "burned out", 1);
	stop_simulation(simulation);
}
