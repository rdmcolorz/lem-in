/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 10:53:09 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_game	*game;
	t_path	*paths;
	int		i;

	i = -1;
	game = init_game();
	if (!parse_file(game))
	{
	//	while (1)
	//		;
		return (0);
	}
	if (!create_rooms(game))
	{
	//	while (1)
	//		;
		return (0);
	}
	if ((paths = multi_bfs(game)) == NULL)
	{
	//	while (1)
	//		;
		return (0);
	}
	//print_graph(game);
	//ft_putchar('\n');
	//print_list(&paths);
	//printf("GAME DATA--------\n");
	//print_game(game);
	print_path(paths, game);
	//free_game(game); TO DO
	//while(1)
	//	;
}
