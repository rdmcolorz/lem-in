/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:34:56 by tyang             #+#    #+#             */
/*   Updated: 2018/03/21 21:08:30 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	counts the number of links in the map, and checkes if the link
**	links to itself, and if the link refers to a room in the map.
*/

int		count_links(char **line, t_game *game)
{
	char	**link;
	int		i;
	int		count;

	i = -1;
	count = 0;
	link = ft_strsplit(line[0], '-');
	if (!ft_strcmp(link[0], link[1]))
	{
		free_2d_array(link);
		return (error_msg("ERROR---room links to self"));
	}
	while (++i < game->nb_rooms)
		count = check_exist(link, game, i, count);
	free_2d_array(link);
	if (count < 2)
		return (error_msg("ERROR---none existing room in link"));
	return (1);
}

/*
**	funtion for count_links that checks if the room exists in the map.
*/

int		check_exist(char **link, t_game *game, int i, int count)
{
	int	x;

	x = -1;
	while (++x < 2)
	{
		if (!ft_strcmp(game->rooms[i].name, link[x]))
		{
			count += 1;
			game->rooms[i].nb_links += 1;
		}
	}
	return (count);
}

/*
**	function for create_rooms, goes to each room and assigns the link to it.
*/

void	put_links(t_game *game)
{
	int		i;
	int		room_i;

	room_i = -1;
	while (++room_i < game->nb_rooms)
	{
		i = 0;
		game->nb_made_l = -1;
		while (game->lines[++i])
			if (ft_strchr(game->lines[i], '-') && game->lines[i][0] != '#')
				link_room(game->lines[i], game, room_i);
	}
}

void	link_room(char *str, t_game *game, int room_i)
{
	int		j;
	char	**link;

	link = ft_strsplit(str, '-');
	if (!ft_strcmp(game->rooms[room_i].name, link[0]))
	{
		j = -1;
		while (++j < game->nb_rooms)
			if (!ft_strcmp(game->rooms[j].name, link[1]))
				game->rooms[room_i].links[++game->nb_made_l] = &game->rooms[j];
	}
	if (!ft_strcmp(game->rooms[room_i].name, link[1]))
	{
		j = -1;
		while (++j < game->nb_rooms)
			if (!ft_strcmp(game->rooms[j].name, link[0]))
				game->rooms[room_i].links[++game->nb_made_l] = &game->rooms[j];
	}
	free_2d_array(link);
}

int		duplicate_links(t_game *game)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	*name;

	i = -1;
	while (++i < game->nb_rooms)
	{
		j = -1;
		while (++j < game->rooms[i].nb_links)
		{
			name = game->rooms[i].links[j]->name;
			k = -1;
			count = 0;
			while (++k < game->rooms[i].nb_links)
			{
				if (!ft_strcmp(name, game->rooms[i].links[k]->name))
					count++;
				if (count > 1)
					return (0);
			}
		}
	}
	return (1);
}
