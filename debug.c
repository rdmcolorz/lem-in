/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:28:13 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 23:37:03 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_game(t_game *game)
{
	int i;

	i = 0;
	printf("number of ants: %i\nnumber of starts: %i\nnumber of ends: %i\n",
					game->ants, game->nb_starts, game->nb_ends);
	if (game->end == NULL || game->start == NULL)
		return (error_msg("ERROR---no start or no end"));
	ft_putendl("---start rooms---");
	while (game->start[i])
	{
		ft_putendl(game->start[i]);
		i++;
	}
	i = 0;
	ft_putendl("---end rooms---");
	while (game->end[i])
	{
		ft_putendl(game->end[i]);
		i++;
	}
	return (0);
}
