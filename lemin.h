/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:07:03 by tyang             #+#    #+#             */
/*   Updated: 2018/03/15 22:16:38 by tyang            ###   ########.fr       */
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

typedef struct		s_room
{
	int				x;
	int				y;
	int				is_start;
	int				is_end;
	int				nb_links;
	char			*name;
	struct s_room	*links;
}					t_room;

typedef struct	s_game
{
	int			ants;
	int			nb_starts;
	int			nb_ends;
	int			nb_rooms;
	int			nb_made_rooms;
	int			nb_links;
	char		**all_links;
	char		**lines;
	t_room		*start;
	t_room		*end;
	t_room		*rooms;
}				t_game;
	
/*
**	file.c
*/

char			*read_stdin();
int				parse_file(t_game *game);
int				parse_line(char *line, t_game *game);
int				parse_room(char **room_data, t_game *game);
int				parse_link_comment(char **arr, t_game *game);
void			number_of_start_end(char **arr, t_game *game);
int				get_array_len(char **arr);
int				is_space_between_lines(char *content);
int				is_number(char *str);
void			count_start_end(char **arr, t_game *game);

/*
**	error_msg.c
*/

int				error_msg(char *msg);
int				error_msg_free(char *str, char *msg);
int				error_msg_free_arr(char **arr, char *msg);
void			*error_msg_void(char *msg);

/*
**	init.c
*/

t_game			*init_game();
t_room			*init_room(char **arr, t_game *game, int flag);


/*
**	create.c
*/

int				create_rooms(t_game *game);
int				create_links(char **line, t_game *game);
int				duplicate_rooms(t_game *game);

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
