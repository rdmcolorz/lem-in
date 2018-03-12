/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/12 11:04:13 by tyang            ###   ########.fr       */
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
	if (ft_atoi(lines[0]) == 0)
		return (error_msg("ERROR---no ants, or invalid input"));
	game->ants = ft_atoi(lines[0]);
	i = 1;
	j = 0;
	while (lines[i])
	{
		if (!ft_strcmp(lines[i], "##start") || !ft_strcmp(lines[i], "##end"))
		{
			i++;
			if (lines[i][0] == 'L' || lines[i][0] == '#')
				return (error_msg("ERR0R---'L' as room name"));
		}
		i++;
	}
	number_of_start_end(lines, game);
	print_game(game);
	return (0);
}

/*	
**	counts the number of start rooms and end rooms
**	so malloc only needs to run once for the whole array.
*/

void	number_of_start_end(char **arr, t_game *game)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], "##start"))
		{
			ft_putendl("start plus one");
			game->nb_starts += 1;
		}
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
**	gets room values into game struct, such as name, x cord, y cord,
**	return 0 if invalid.
*/

int		get_room(char *str, t_game *game)
{
	int		i;
	char	**room_arr;

	room_arr = ft_strsplit(str, ' ');
	i = 0;
	if (get_array_len(room_arr) != 3)
		return (0);
	if (room_arr[0][0] == 'L' || room_arr[0][0] == '#')
		return (0);
	while (room_arr[1][i])
	{
		if (!ft_isdigit(room_arr[1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (room_arr[2][i])
	{
		if (!ft_isdigit(room_arr[2][i]))
			return (0);
		i++;
	}
	game->ants = 0;
	return (1);
}

int		get_array_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
