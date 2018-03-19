/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/18 22:34:11 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_game	*game;
	char	**route;
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
	route = bfs(game);
	while (route[++i])
		printf("%s\n", route[i]);
	print_path(route, game);
	//printf("GAME DATA--------\n");
	//print_game(game);
	//free_game(game); TO DO
	//while(1)
	//	;
}
