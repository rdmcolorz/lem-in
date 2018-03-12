/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:07:03 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 23:37:10 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEMIN_H
#define LEMIN_H
# define BUFF_SIZE 4096
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"


typedef struct	s_game
{
	int			ants;
	int			nb_starts;
	int			nb_ends;
	char		**start;
	char		**end;
}				t_game;

/*
**	file.c
*/

char			*read_file(char *file);
int				parse_file(char *file, t_game *game);
char			**add_to_array(char **arr, char *str);

/*
**	error_msg.c
*/

int				error_msg(char *msg);
void			*error_msg_void(char *msg);

/*
**	game.c
*/

t_game			*init_game();

/*
**	debug.c
*/
int				print_game(t_game *game);
#endif
