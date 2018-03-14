/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:38:35 by tyang             #+#    #+#             */
/*   Updated: 2018/03/13 21:07:19 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}

int		error_msg_free_arr(char **arr, char *msg)
{
	free_2d_array(arr);
	ft_putendl_fd(msg, 2);
	return (0);
}

void	*error_msg_void(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (NULL);
}
