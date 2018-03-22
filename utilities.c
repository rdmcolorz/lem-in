/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:09 by tyang             #+#    #+#             */
/*   Updated: 2018/03/22 00:33:27 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	gets room values into room struct, such as name, x cord, y cord,
**	return 0 if invalid.
*/

int		get_array_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		get_struct_arr_len(t_room **steps)
{
	int i;

	i = 0;
	while (steps[i])
		i++;
	return (i);
}

int		get_list_len(t_path *path)
{
	t_path	*curr;
	int		i;

	i = 0;
	curr = path;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
