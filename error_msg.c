/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:38:35 by tyang             #+#    #+#             */
/*   Updated: 2018/03/11 19:40:49 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}

void	*error_msg_void(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (NULL);
}
