/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:22:27 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 00:08:57 by tyang            ###   ########.fr       */
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
			if (q->head->room->links[i]->visited == 0 &&
				q->head->room->links[i]->blocked == 0)
			{
				push_queue(q, q->head->room->links[i]);
				q->head->room->links[i]->visited = 1;
				q->head->room->links[i]->prev_room = q->head->room;
			}
			if (q->head->room->links[i]->is_end == 1)
				return (get_shortest_path(q->head->room->links[i], game));
		}
		pop_queue(q);
	}
	return (NULL);
}

t_path	*multi_bfs(t_game *game)
{
	t_room	*start;
	t_room	*end;
	int		nb_paths;
	t_path	*paths;
	char	**shortest;

	paths = NULL;
	start = find_start_room(game);
	end = find_end_room(game);
	if (start->nb_links < end->nb_links)
		nb_paths = start->nb_links;
	else
		nb_paths = end->nb_links;
	while (nb_paths > 0)
	{
		restart_map(game);
		if ((shortest = bfs(game)) == NULL)
		{
			if (paths == NULL)
				return (error_msg_void("ERROR---no path to end"));
			return (paths);
		}
		paths = add_path(shortest, paths);
		nb_paths--;
	}
	return (paths);
}

t_path	*add_path(char **path, t_path *head)
{
	t_path	*new;
	
	new = ft_memalloc(sizeof(t_path));
	new->path = path;
	new->next = NULL;
	if (head != NULL)
		new->next = head;
	return (new);
}

char	**get_shortest_path(t_room *room, t_game *game)
{
	int		count;
	char	**route;
	t_room	*temp;
	int		i;

	count = 0;
	temp = room;
	while (temp->is_start != 1)
	{
		temp = temp->prev_room;
		count++;
	}
	route = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	route[count] = 0;
	while (--count >= 0)
	{
		i = -1;
		while (++i < game->nb_rooms)
			if (!ft_strcmp(game->rooms[i].name, room->name))
				if (game->rooms[i].is_end != 1)
					game->rooms[i].blocked = 1;
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
	{
		game->rooms[i].visited = 0;
		//game->rooms[i].prev_room = NULL;
	}
}
