/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:50:18 by tyang             #+#    #+#             */
/*   Updated: 2018/03/17 23:20:15 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_game	*init_game(void)
{
	t_game *game;

	game = (t_game*)ft_memalloc(sizeof(t_game));
	game->ants = 0;
	game->nb_starts = 0;
	game->nb_ends = 0;
	game->nb_rooms = 0;
	game->nb_made_rooms = 0;
	game->nb_links = 0;
	game->nb_made_l = 0;
	game->flag = 0;
	game->start = NULL;
	game->end = NULL;
	game->rooms = NULL;
	return (game);
}

t_room	*init_room(char **arr, t_game *game)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->is_start = (game->flag == 1) ? 1 : 0;
	room->is_end = (game->flag == 2) ? 1 : 0;
	room->name = arr[0];
	room->nb_links = 0;
	room->links = NULL;
	if (room->is_start)
		game->start = room;
	if (room->is_end)
		game->end = room;
	game->nb_made_rooms += 1;
	game->flag = 0;
	return (room);
}

void	init_all_room_links(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->nb_rooms)
	{
		if (game->rooms[i].nb_links != 0)
		{
			game->rooms[i].links = ft_memalloc(sizeof(t_room*) *
											game->rooms[i].nb_links);
		}
	}
}
