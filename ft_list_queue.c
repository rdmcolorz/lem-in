/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 13:27:18 by tyang             #+#    #+#             */
/*   Updated: 2018/03/19 21:29:23 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node		*new_node(t_room *room)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new->room = room;
	new->next = NULL;
	return (new);
}

t_queue		*init_queue(void)
{
	t_queue	*new;

	new = (t_queue*)ft_memalloc(sizeof(t_queue));
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

void		push_queue(t_queue *queue, t_room *room)
{
	t_node	*new;

	new = new_node(room);
	if (queue->tail == NULL)
	{
		queue->head = new;
		queue->tail = new;
		return ;
	}
	queue->tail->next = new;
	queue->tail = new;
}

t_node		*pop_queue(t_queue *queue)
{
	t_node	*temp;

	temp = queue->head;
	if (queue->head == NULL)
		return (NULL);
	queue->head = queue->head->next;
	if (queue->head == NULL)
		queue->tail = NULL;
	return (temp);
}
