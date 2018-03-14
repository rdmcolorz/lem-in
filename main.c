/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 22:48:09 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (error_msg("usage: ./lem-in target_file"));
	game = init_game();
	if (parse_file(av[1], game) == 0)
		return (0);
	while(1)
		;
}
