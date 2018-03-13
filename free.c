/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:04:38 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 10:38:57 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_game(t_game *game)
{
	ft_lstfree(game->start);
	ft_lstfree(game->end);
	free(game);
}

void	free_room(t_room *room)
{
	ft_lstfree(room->links);
	free(room->name);
	free(room);
}
