/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:10:34 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 10:26:53 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_path(t_path *paths, t_game *game)
{
	int		i;
	int		j;
	int		steps_len;

	i = 0;
	while (paths != NULL)
	{
		steps_len = get_struct_arr_len(paths->steps);
		while (++i <= game->ants)
		{
			j = -1;
			while (++j < steps_len)
			{
				ft_putchar('L');
				ft_putnbr(i);
				ft_putchar('-');
				ft_putstr(paths->steps[j]->name);
				ft_putchar('\n');
			}
		}
		paths = paths->next;
	}
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
