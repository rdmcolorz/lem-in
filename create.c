/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:34:56 by tyang             #+#    #+#             */
/*   Updated: 2018/03/16 23:52:27 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_rooms(t_game *game)
{
	int		i;
	int		flag;
	char	**curr;

	i = 0;
	flag = 0;
	game->rooms = ft_memalloc(sizeof(t_room) * game->nb_rooms);
	while (game->lines[++i])
	{
		curr = ft_strsplit(game->lines[i], ' ');
		if (get_array_len(curr) == 1)
		{
			if (flag == 1 || flag == 2)
				return (error_msg_free_arr(curr, "ERROR---invalid room"));
			if (!ft_strcmp(curr[0], "##start"))
				flag = 1;
			if (!ft_strcmp(curr[0], "##end"))
				flag = 2;
			if (curr[0][0] != '#')
				if (!count_links(curr, game))
					return (0);
		}
		else
		{
			game->rooms[game->nb_made_rooms] = *init_room(curr, game, flag);
			game->nb_made_rooms += 1;
			flag = 0;
		}
	}
	init_all_room_links(game);
	put_links(game);
	//if (!duplicate_rooms(game) || !duplicate_links(game))
	//	return (error_msg_free_arr(curr, "ERROR---duplicate rooms/links"));
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

int		count_links(char **line, t_game *game)
{
	char	**link;
	int		i;
	int		count;
	int		count2;

	i = -1;
	count = 0;
	count2 = 0;
	link = ft_strsplit(line[0], '-');
	if (!ft_strcmp(link[0], link[1]))
		return (error_msg_free_arr(link, "ERROR---room links to self"));
	while (++i < game->nb_rooms)
	{
		if (!ft_strcmp(game->rooms[i].name, link[0]))
		{
			count += 1;
			game->rooms[i].nb_links += 1;
		}
		if (!ft_strcmp(game->rooms[i].name, link[1]))
		{
			count2 += 1;
			game->rooms[i].nb_links += 1;
		}
	}
	if (count == 0 || count2 == 0)
		return (error_msg_free_arr(link, "ERROR---none existing room in link"));
	free_2d_array(link);
	return (1);
}


void	put_links(t_game *game)
{
	int		i;
	int		j;
	int		room_i;
	int		curr_link;
	int		link_i;
	char	**link;

	curr_link = -1;
	room_i = -1;
	while (++room_i < game->nb_rooms)
	{
		i = 0;
		link_i = -1;
		while (game->lines[++i])
		{
			if (ft_strchr(game->lines[i], '-') && game->lines[i][0] != '#')
			{
				link = ft_strsplit(game->lines[i], '-');
				if (!ft_strcmp(game->rooms[room_i].name, link[0]))
				{
					j = -1;
					while (++j < game->nb_rooms)
						if (!ft_strcmp(game->rooms[j].name, link[1]))
							game->rooms[room_i].links[++link_i] = &game->rooms[j];
				}
				if (!ft_strcmp(game->rooms[room_i].name, link[1]))
				{
					j = -1;
					while (++j < game->nb_rooms)
						if (!ft_strcmp(game->rooms[j].name, link[0]))
							game->rooms[room_i].links[++link_i] = &game->rooms[j];
				}
			}
		}
	}
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
