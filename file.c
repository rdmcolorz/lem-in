/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/14 10:03:13 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	reads file from filename as argument.
**	returns content as char array.
*/

char	*read_stdin()
{
	char	*content;
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;

	ret = 0;
	content = NULL;
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
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

int		parse_file(t_game *game)
{
	char	*content;
	char	**lines;
	int		i;

	if ((content = read_stdin()) == NULL)
		return (0);
	if (is_space_between_lines(content))
		return (error_msg("ERROR---empty space between lines"));
	lines = ft_strsplit(content, '\n');
	if ((game->ants = ft_atoi(lines[0])) == 0)
	{
		free_2d_array(lines);
		return (error_msg("ERROR---no ants, or invalid input"));
	}
	i = 0;
	while (lines[++i])
		if (!parse_line(lines[i]))
			return (free_2d_array(lines));
	free_2d_array(lines);
	free(content);
	return (1);
}

int		is_space_between_lines(char *content)
{
	int	i;

	i = -1;
	while (content[++i])
		if (content[i] == '\n')
			if (content[i + 1] == '\n')
				return (1);
	return (0);
}

int		parse_line(char *line)
{
	int		i;
	int		arr_len;
	char	**curr;

	i = -1;
	curr = ft_strsplit(line, ' ');
	arr_len = get_array_len(curr);
	if (arr_len == 1)
		if (curr[0][0] != '#')
			if (!ft_strchr(curr[0], '-'))
				return (error_msg_free_arr(curr, "ERROR---invalid comment"));
	if (arr_len == 3)
		if (!parse_room(curr))
			return (0);
	if (arr_len != 1 && arr_len != 3)
		return (error_msg_free_arr(curr, "ERROR---invlaid format"));
	free_2d_array(curr);
	return (1);
}

/*
**	read in room_data string array
**	return 0 if invalid
*/

int		parse_room(char **room_data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (room_data[0][0] == 'L')
	{
		free_2d_array(room_data);
		return (error_msg("ERROR---'L' as room name"));
	}
	while (room_data[i])
	{
		while (room_data[i][j])
		{
			if (!ft_isdigit(room_data[i][j]))
			{
				free_2d_array(room_data);
				return (error_msg("ERROR---cordinates not a number"));
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	counts the number of start rooms and end rooms
**	so malloc only needs to run once for the whole array.
*/

void	make_map(char **arr, t_game *game)
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
