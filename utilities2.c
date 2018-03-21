/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 23:36:52 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_number(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
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

void	count_start_end(char **arr, t_game *game)
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
