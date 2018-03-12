/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 20:14:20 by tyang            ###   ########.fr       */
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
		return (error_msg_void("Cannot open file"));
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
		return (error_msg_void("Empty file"));
	return (content);
}

int		parse_file(char *file, t_game *game)
{
	char	*content;
	char	**lines;

	if ((content = read_file(file)) == NULL)
		return (0);
	lines = ft_strsplit(content, '\n');
	game->ants = 0;
	return (0);
}
