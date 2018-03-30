/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:22:27 by tyang             #+#    #+#             */
/*   Updated: 2018/03/29 20:27:59 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*add_path(t_room **steps, t_path *head)
{
	t_path	*new;

	new = ft_memalloc(sizeof(t_path));
	new->steps = steps;
	new->len = get_struct_arr_len(steps);
	new->assign_ants = 0;
	new->next = NULL;
	if (head != NULL)
		new->next = head;
	return (new);
}

t_room	**get_shortest_path(t_queue *q, t_room *room, t_game *game)
{
	t_room	**route;
	t_room	*temp;
	int		count;

	count = 0;
	temp = room;
	while (temp->is_start != 1)
	{
		temp = temp->prev_room;
		count++;
	}
	route = (t_room**)ft_memalloc(sizeof(t_room*) * (count + 1));
	route[count] = 0;
	while (--count >= 0)
	{
		block_room(route, room, game, count);
		if (room->prev_room != NULL)
			room = room->prev_room;
	}
	while (q->head)
		pop_queue(q);
	free(q);
	return (route);
}

void	block_room(t_room **route, t_room *room, t_game *game, int count)
{
	int i;

	i = -1;
	while (++i < game->nb_rooms)
	{
		if (!ft_strcmp(game->rooms[i].name, room->name))
		{
			if (game->rooms[i].is_end != 1)
				game->rooms[i].blocked = 1;
			route[count] = &(game->rooms[i]);
		}
	}
}
