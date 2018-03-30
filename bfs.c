/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:22:27 by tyang             #+#    #+#             */
/*   Updated: 2018/03/29 20:27:29 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	**bfs(t_game *game)
{
	t_queue	*q;
	int		i;

	q = init_queue();
	push_queue(q, find_start_room(game));
	while (q->head != NULL)
	{
		i = -1;
		while (++i < q->head->room->nb_links)
		{
			if (q->head->room->links[i]->visited == 0 &&
				q->head->room->links[i]->blocked == 0)
			{
				push_queue(q, q->head->room->links[i]);
				q->head->room->links[i]->visited = 1;
				q->head->room->links[i]->prev_room = q->head->room;
			}
			if (q->head->room->links[i]->is_end == 1)
				return (get_shortest_path(q, q->head->room->links[i], game));
		}
		pop_queue(q);
	}
	free(q);
	return (NULL);
}

t_path	*multi_bfs(t_game *game)
{
	t_room	*start;
	t_room	*end;
	t_room	**shortest;
	t_path	*paths;
	int		nb_paths;

	paths = NULL;
	start = find_start_room(game);
	end = find_end_room(game);
	if (start->nb_links < end->nb_links)
		nb_paths = start->nb_links;
	else
		nb_paths = end->nb_links + 1;
	while (--nb_paths > 0)
	{
		restart_map(game);
		if ((shortest = bfs(game)) == NULL)
		{
			if (paths == NULL)
				return (error_msg_void("ERROR---no path to end"));
			return (paths);
		}
		paths = add_path(shortest, paths);
	}
	return (paths);
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

t_room	*find_end_room(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->nb_rooms)
	{
		if (game->rooms[i].is_end == 1)
			return (&game->rooms[i]);
	}
	return (NULL);
}

void	restart_map(t_game *game)
{
	int i;

	i = 0;
	while (++i < game->nb_rooms)
		game->rooms[i].visited = 0;
}
