/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:50:18 by tyang             #+#    #+#             */
/*   Updated: 2018/03/14 17:14:49 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_game	*init_game()
{
	t_game *game;

	game = (t_game*)ft_memalloc(sizeof(t_game));
	game->ants = 0;
	game->nb_starts = 0;
	game->nb_ends = 0;
	game->nb_rooms = 0;
	game->nb_links = 0;
	game->starts = NULL;
	game->ends = NULL;
	game->rooms = NULL;
	return (game);
}

t_room	*init_new_room(char **arr, int flag)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->is_start = (flag == 1) ? 1 : 0;
	room->is_end = (flag == 2) ? 1 : 0;
	room->name = arr[0];
	room->links = NULL;
	return (room);
}
