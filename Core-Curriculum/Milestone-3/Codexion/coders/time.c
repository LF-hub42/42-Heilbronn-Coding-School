/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:20:00 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <unistd.h>

long long	current_time_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long)now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	wait_ms(long long duration)
{
	if (duration > 0)
		usleep((useconds_t)(duration * 1000));
}
