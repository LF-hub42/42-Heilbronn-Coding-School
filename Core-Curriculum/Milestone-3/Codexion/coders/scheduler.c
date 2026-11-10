/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:30 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	request_before(t_request *first, t_request *second)
{
	t_simulation	*simulation;

	simulation = first->coder->simulation;
	if (simulation->config.edf && first->deadline != second->deadline)
		return (first->deadline < second->deadline);
	return (first->sequence < second->sequence);
}

static void	swap_requests(t_request **first, t_request **second)
{
	t_request	*temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

void	sift_up(t_heap *heap, int index)
{
	int	parent;

	while (index > 0)
	{
		parent = (index - 1) / 2;
		if (request_before(heap->items[parent], heap->items[index]))
			break ;
		swap_requests(&heap->items[parent], &heap->items[index]);
		index = parent;
	}
}

void	sift_down(t_heap *heap, int index)
{
	int	child;

	while (index * 2 + 1 < heap->size)
	{
		child = index * 2 + 1;
		if (child + 1 < heap->size
			&& request_before(heap->items[child + 1], heap->items[child]))
			child++;
		if (request_before(heap->items[index], heap->items[child]))
			break ;
		swap_requests(&heap->items[index], &heap->items[child]);
		index = child;
	}
}
