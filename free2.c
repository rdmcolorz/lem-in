/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:36:01 by tyang             #+#    #+#             */
/*   Updated: 2018/03/23 18:53:00 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_path(t_path *paths)
{
	t_path	*temp;

	temp = NULL;
	while (paths != NULL)
	{
		temp = paths;
		free(paths);
		paths = paths->next;
	}
}
