/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:04:38 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 22:50:35 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_game(t_game *game)
{
	ft_lstfree(&(game->starts));
	ft_lstfree(&(game->ends));
	free(game);
}

void	free_room(t_room *room)
{
	ft_lstfree(&(room->links));
	free(room->name);
	free(room);
}

int		free_2d_array(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (0);
}

int		free_2_2d_array(char **arr, char **arr2)
{
	free_2d_array(arr);
	free_2d_array(arr2);
	return (0);
}
