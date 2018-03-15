/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:34:56 by tyang             #+#    #+#             */
/*   Updated: 2018/03/14 23:47:25 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_map(t_game *game)
{
	int		i;
	int		flag;
	char	**curr_line;

	i = -1;
	flag = 0;
	game->rooms = ft_memalloc(sizeof(t_room) * game->nb_rooms);
	while (game->lines[++i])
	{
		curr_line = ft_strsplit(game->lines[i], ' ');
		if (get_array_len(curr_line) == 1)
		{
			if (!ft_strcmp(curr_line[0], "##start"))
				flag = 1;
			if (!ft_strcmp(curr_line[0], "##end"))
				flag = 2;
		}
		else
		{
			game->rooms[game->nb_made_rooms] = *init_new_room(curr_line, flag);
			game->nb_made_rooms += 1;
			flag = 0;
		}
	}
}
