/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/22 10:55:18 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
		return (error_msg_free(content, "ERROR---empty space between lines"));
	lines = ft_strsplit(content, '\n');
	free(content);
	count_start_end(lines, game);
	if ((game->ants = ft_atoi(lines[0])) <= 0 || !is_number(lines[0]))
		return (error_msg_free_arr(lines, "ERROR---no ants, or invalid input"));
	i = 0;
	while (lines[++i])
		if (!parse_line(lines[i], game))
			return (free_2d_array(lines));
	if (game->nb_links == 0 || game->nb_starts != 1
		|| game->nb_ends != 1 || game->nb_rooms == 0)
		return (error_msg_free_arr(lines, "ERROR---empty link/room/start/end"));
	game->lines = lines;
	return (1);
}

/*
**	reads file from filename as argument.
**	returns content as char array.
*/

char	*read_stdin(void)
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

int		parse_line(char *line, t_game *game)
{
	int		arr_len;
	char	**curr;

	curr = ft_strsplit(line, ' ');
	arr_len = get_array_len(curr);
	if (arr_len != 1 && arr_len != 3 && curr[0][0] != '#')
		return (error_msg_free_arr(curr, "ERROR---invlaid format"));
	if (arr_len == 1)
		if (!parse_link_comment(curr, game))
			return (0);
	if (arr_len == 3)
		if (!parse_room(curr, game))
			return (0);
	free_2d_array(curr);
	return (1);
}

int		parse_link_comment(char **arr, t_game *game)
{
	if (arr[0][0] == '#')
		return (1);
	if (!ft_strchr(arr[0], '-'))
		return (error_msg_free_arr(arr, "ERROR---invalid comment"));
	game->nb_links += 1;
	return (1);
}

/*
**	read in room_data string array
**	return 0 if invalid
*/

int		parse_room(char **room_d, t_game *game)
{
	int i;
	int j;

	i = 0;
	if (room_d[0][0] == 'L')
		return (error_msg_free_arr(room_d, "ERROR---'L' as room name"));
	while (room_d[++i])
	{
		if ((room_d[i][0] == '-' &&
			ft_strlen(room_d[i]) > 1) || ft_isdigit(room_d[i][0]))
		{
			j = 0;
			while (room_d[i][++j])
			{
				if (!ft_isdigit(room_d[i][j]))
					return (error_msg_free_arr(room_d, "ERROR---invalid x y"));
			}
		}
		else
			return (error_msg_free_arr(room_d, "ERROR---invalid x y"));
	}
	game->nb_rooms += 1;
	return (1);
}
