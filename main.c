/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/29 20:21:39 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_game	*game;
	t_path	*paths;
	int		steps;

	game = init_game();
	if (!parse_file(game))
		return (0);
	if (!create_rooms(game))
		return (0);
	if (!(paths = multi_bfs(game)))
		return (0);
	list_rev(&paths);
	print_graph(game);
	ft_putchar('\n');
	steps = assign_ants(paths, game);
	print_steps(&paths, steps);
	while (1)
		;
}
