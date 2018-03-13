/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 11:30:29 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	reads file from filename as argument.
**	returns content as char array.
*/

char	*read_file(char *file)
{
	char	*content;
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		fd;
	int		ret;

	ret = 0;
	content = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (error_msg_void("ERROR---Cannot open file"));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (content == NULL)
			content = ft_strdup(buff);
		else
		{
			del = ft_strjoin(content, buff);
			free(content);
			content = del;
		}
	}
	if (content == NULL)
		return (error_msg_void("ERROR---Empty file"));
	return (content);
}

/*
**	gets content char array from read_file.
**	splits it into string array seperated by '\n'
**	if content is invalid, return 0
*/

int		parse_file(char *file, t_game *game)
{
	char	*content;
	char	**lines;
	int		i;
	int		j;

	if ((content = read_file(file)) == NULL)
		return (0);
	lines = ft_strsplit(content, '\n');
	if ((game->ants = ft_atoi(lines[0])) == 0)
		return (error_msg("ERROR---no ants, or invalid input"));
	i = 0;
	j = 0;
	number_of_start_end(lines, game);
	while (lines[++i])
		if (!ft_strcmp(lines[i], "##start") || !ft_strcmp(lines[i], "##end"))
			if (lines[i + 1][0] == 'L' || lines[i + 1][0] == '#')
				return (error_msg("ERROR---'L' as room name"));
			
	print_game(game);
	return (0);
}

/*
**	counts the number of start rooms and end rooms
**	so malloc only needs to run once for the whole array.
*/

void	number_of_start_end(char **arr, t_game *game)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], "##start"))
			game->nb_starts += 1;
		else if (!ft_strcmp(arr[i], "##end"))
			game->nb_ends += 1;
		i++;
	}
}


/*
	game->start = (char**)ft_memalloc(sizeof(char*) * game->nb_starts);
	game->end = (char**)ft_memalloc(sizeof(char*) * game->nb_starts);
*/

/*
**	gets room values into room struct, such as name, x cord, y cord,
**	return 0 if invalid.
*/

t_room	*get_room(char *str, int flag)
{
	int		i;
	char	**room_arr;
	t_room	*room;

	room_arr = ft_strsplit(str, ' ');
	i = -1;
	if (get_array_len(room_arr) != 3)
		return (0);
	if (room_arr[0][0] == 'L' || room_arr[0][0] == '#')
		return (0);
	while (room_arr[1][++i])
		if (!ft_isdigit(room_arr[1][i]))
			return (0);
	i = -1;
	while (room_arr[2][++i])
		if (!ft_isdigit(room_arr[2][i]))
			return (0);
	room = init_new_room(room_arr, flag);
	return (room);
}

int		get_array_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
