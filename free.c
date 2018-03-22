/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:04:38 by tyang             #+#    #+#             */
/*   Updated: 2018/03/21 21:50:03 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_game(t_game *game)
{
	int i;
	int j;

	i = -1;
	free_2d_array(game->lines);
	while (++i < game->nb_rooms)
	{
		free(game->rooms[i].name);
		free(game->rooms[i].ant_name);
		j = -1;
		while (++j < game->rooms[i].nb_links)
			free(game->rooms[i].links[j]);
	}
	free(game);
}

int		free_2d_array(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
	return (0);
}

int		free_2_2d_array(char **arr, char **arr2)
{
	free_2d_array(arr);
	free_2d_array(arr2);
	return (0);
}

void	free_ants_list(t_ant *head)
{
	t_ant	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_queue(t_queue *q)
{
	t_node *temp;

	while (q->head != NULL)
	{
		temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
	free(q);
}

void	free_rooms(t_game **game)
{
	int		i;
	t_game	*curr;

	i = -1;
	curr = *game;
	while (&(curr->rooms[i]))
		free(&(curr->rooms[i]));
	free(curr->rooms);
}
