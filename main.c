/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:36:59 by tyang             #+#    #+#             */
/*   Updated: 2018/03/18 14:37:28 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main()
{
	t_game	*game;

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
	t_queue *q = init_queue();
 	push_queue(q, &game->rooms[1]);
 	push_queue(q, &game->rooms[2]);
	pop_queue(q);
 	push_queue(q, &game->rooms[2]);
 	push_queue(q, &game->rooms[1]);
 	push_queue(q, &game->rooms[0]);
 	push_queue(q, &game->rooms[2]);
	print_queue(q);
	printf("GAME DATA--------\n");
	print_game(game);
	//free_game(game); TO DO
	//while(1)
	//	;
}
