/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:07:03 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 21:39:40 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEMIN_H
# define LEMIN_H
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
	int			nb_rooms;
	t_list		*starts;
	t_list		*ends;
}				t_game;

typedef struct	s_room
{
	int			x;
	int			y;
	int			is_start;
	int			is_end;
	char		*name;
	t_list		*links;
}				t_room;
	
/*
**	file.c
*/

char			*read_file(char *file);
int				parse_file(char *file, t_game *game);
int				parse_line(char **curr);
int				parse_room(char **room_data);
void			number_of_start_end(char **arr, t_game *game);
t_room			*get_room(char *str, int flag);
int				get_array_len(char **arr);
int				is_space_between_lines(char *content);

/*
**	error_msg.c
*/

int				error_msg(char *msg);
void			*error_msg_void(char *msg);

/*
**	init.c
*/

t_game			*init_game();
t_room			*init_new_room(char **arr, int flag);

/*
**	free.c
*/

void			free_game(t_game *game);
void			free_room(t_room *room);
int				free_2d_array(char **arr);
int				free_2_2d_array(char **arr, char **arr2);

/*
**	debug.c
*/

int				print_game(t_game *game);
#endif
