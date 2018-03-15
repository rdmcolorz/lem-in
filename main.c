/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/14 17:12:10 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main()
{
	t_game	*game;

	game = init_game();
	if (!parse_file(game))
	{
		while (1)
			;
		return (0);
	}
	print_game(game);
	while(1)
		;
}
