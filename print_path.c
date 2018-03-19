/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:10:34 by tyang             #+#    #+#             */
/*   Updated: 2018/03/18 23:01:02 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_path(char **route, t_game *game)
{
	int		i;
	int		j;
	int		steps;

	i = 0;
	steps = get_array_len(route);
	while (++i <= game->ants)
	{
		j = -1;
		while (++j < steps)
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			ft_putstr(route[j]);
			ft_putchar('\n');
		}
	}
}
