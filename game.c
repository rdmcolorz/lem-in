/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:50:18 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 20:13:30 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_game	*init_game()
{
	t_game *game;

	game = (t_game*)ft_memalloc(sizeof(t_game));
	game->ants = 0;
	game->start = NULL;
	game->end = NULL;
	return (game);
}
