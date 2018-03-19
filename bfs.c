/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:22:27 by tyang             #+#    #+#             */
/*   Updated: 2018/03/18 21:59:18 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**bfs(t_game *game)
{
	t_queue	*q;
	int		i;
	t_room	*start;

	q = init_queue();
	start = find_start_room(game);
	push_queue(q, start);
	while (q->head != NULL)
	{
		i = -1;
		while (++i < q->head->room->nb_links)
		{
			if (q->head->room->links[i]->visited != 1)
			{
				push_queue(q, q->head->room->links[i]);
				q->head->room->links[i]->visited = 1;
				q->head->room->links[i]->prev_room = q->head->room;
			}
			if (q->head->room->links[i]->is_end == 1)
				return (get_shortest_path(q->head->room->links[i]));
		}
		//print_queue(q);
		pop_queue(q);
	}
	return (error_msg_void("no path to end"));
}

char	**get_shortest_path(t_room *room)
{
	int		count;
	char	**route;
	t_room	*temp;

	count = 0;
	temp = room;
	while (temp->is_start != 1)
	{
		temp = temp->prev_room;
		count++;
	}
	route = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	route[count] = 0;
	printf("number of steps: %i\n", count);
	while (--count >= 0)
	{
		route[count] = ft_strdup(room->name);
		if (room->prev_room != NULL)
			room = room->prev_room;
	}
	return (route);
}

t_room	*find_start_room(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->nb_rooms)
	{
		if (game->rooms[i].is_start == 1)
		{
			game->rooms[i].visited = 1;
			return (&game->rooms[i]);
		}
	}
	return (NULL);
}
