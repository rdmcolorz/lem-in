/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:57:01 by tyang             #+#    #+#             */
/*   Updated: 2018/03/20 23:35:11 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	list_rev(t_path **head)
{
	t_path *curr;
	t_path *prev;
	t_path *next;

	prev = NULL;
	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
