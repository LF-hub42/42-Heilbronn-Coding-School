/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:20:00 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdlib.h>

int	heap_push(t_heap *heap, t_request *request)
{
	t_request	**new_items;
	int			index;

	if (heap->size == heap->capacity)
	{
		new_items = malloc(heap->capacity * 2 * sizeof(t_request *));
		if (!new_items)
			return (0);
		index = 0;
		while (index < heap->size)
		{
			new_items[index] = heap->items[index];
			index++;
		}
		free(heap->items);
		heap->items = new_items;
		heap->capacity *= 2;
	}
	heap->items[heap->size] = request;
	sift_up(heap, heap->size++);
	return (1);
}

t_request	*heap_peek(t_heap *heap)
{
	if (heap->size == 0)
		return (NULL);
	return (heap->items[0]);
}

void	heap_pop(t_heap *heap)
{
	if (heap->size == 0)
		return ;
	heap->items[0] = heap->items[--heap->size];
	if (heap->size > 0)
		sift_down(heap, 0);
}

void	heap_remove(t_heap *heap, t_request *request)
{
	int	index;

	index = 0;
	while (index < heap->size && heap->items[index] != request)
		index++;
	if (index == heap->size)
		return ;
	heap->items[index] = heap->items[--heap->size];
	if (index < heap->size)
	{
		sift_up(heap, index);
		sift_down(heap, index);
	}
}

void	free_heap(t_heap *heap)
{
	free(heap->items);
	heap->items = NULL;
	heap->size = 0;
	heap->capacity = 0;
}
