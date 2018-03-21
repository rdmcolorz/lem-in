/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:10:34 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 23:44:35 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_ants_ended(t_ant *head)
{
	t_ant	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (!curr->at_end)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	print_list(t_path **paths)
{
	int		steps;
	t_path	*curr;
	int		i;

	curr = *paths;
	while (curr != NULL)
	{
		i = -1;
		steps = get_struct_arr_len(curr->steps);
		ft_putendl("---start print---");
		while (++i < steps)
			ft_putendl(curr->steps[i]->name);
		curr = curr->next;
	}
}

void	print_graph(t_game *game)
{
	int i;

	i = -1;
	while (game->lines[++i])
		ft_putendl(game->lines[i]);
}
