/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:34:56 by tyang             #+#    #+#             */
/*   Updated: 2018/03/23 21:11:44 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_rooms(t_game *game)
{
	int		i;
	char	**curr;

	i = 0;
	game->rooms = (t_room*)ft_memalloc(sizeof(t_room) * (game->nb_rooms));
	while (game->lines[++i])
	{
		curr = ft_strsplit(game->lines[i], ' ');
		if (get_array_len(curr) == 1)
			if (!get_flag(curr, game))
				return (0);
		if (get_array_len(curr) == 3 && curr[0][0] != '#')
			game->rooms[game->nb_made_rooms] = init_room(curr, game);
		free_2d_array(curr);
	}
	init_all_room_links(game);
	put_links(game);
	if (!duplicate_rooms(game))
		return (error_msg("ERROR---duplicate rooms/links"));
	return (1);
}

int		get_flag(char **curr, t_game *game)
{
	if (get_array_len(curr) > 1)
		return (1);
	if (game->flag == 1 || game->flag == 2)
		return (error_msg_free_arr(curr, "ERROR---invalid room"));
	if (curr[0][0] != '#')
	{
		if (!count_links(curr, game))
		{
			free_2d_array(curr);
			return (0);
		}
	}
	if (!ft_strcmp(curr[0], "##start"))
		game->flag = 1;
	if (!ft_strcmp(curr[0], "##end"))
		game->flag = 2;
	return (1);
}

int		duplicate_rooms(t_game *game)
{
	char	*curr_name;
	int		count;
	int		i;
	int		j;

	i = -1;
	while (++i < game->nb_rooms)
	{
		curr_name = game->rooms[i].name;
		j = -1;
		count = 0;
		while (++j < game->nb_rooms)
		{
			if (!ft_strcmp(curr_name, game->rooms[j].name))
				count++;
			if (count > 1)
				return (0);
		}
	}
	return (1);
}
