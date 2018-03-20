/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:10:34 by tyang             #+#    #+#             */
/*   Updated: 2018/03/19 23:52:27 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_path(t_path *paths, t_game *game)
{
	int		i;
	int		j;
	int		steps;

	i = 0;
	while (paths != NULL)
	{
		steps = get_array_len(paths->path);
		while (++i <= game->ants)
		{
			j = -1;
			while (++j < steps)
			{
				ft_putchar('L');
				ft_putnbr(i);
				ft_putchar('-');
				ft_putstr(paths->path[j]);
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
		steps = get_array_len(curr->path);
		ft_putendl("---start print---");
		while (++i < steps)
			ft_putendl(curr->path[i]);
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
