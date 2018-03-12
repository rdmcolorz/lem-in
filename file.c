/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 23:37:01 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	}
	//print_game(game);
	return (0);
}

void	number_of_start_end(char **arr, t_game *game)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], "##start"))
			game->nb_starts += 1; //TO DO: get the start and end values.
		else if (!ft_strcmp(arr[i], "##end"))
			game->nb_ends += 1;
		i++;
	}
	game->start = (char**)ft_memalloc(sizeof(char*) * game->nb_starts);
	game->end = (char**)ft_memalloc(sizeof(char*) * game->nb_starts);
}
