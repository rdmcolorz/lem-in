/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:10:34 by tyang             #+#    #+#             */
/*   Updated: 2018/03/22 01:16:36 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		assign_ants(t_path *paths, t_game *game)
{
	int		i;
	int		all_steps;
	int		average_path_steps;
	int		leftovers;
	t_path	*curr;

	i = 0;
	curr = paths;
	all_steps = game->ants;
	while (curr != NULL)
	{
		all_steps += curr->len;
		curr = curr->next;
	}
	average_path_steps = all_steps / get_list_len(paths);
	leftovers = all_steps % get_list_len(paths);
	curr = paths;
	while (curr != NULL)
	{
		curr->assign_ants = average_path_steps - curr->len;
		if (curr->next == NULL)
			curr->assign_ants += leftovers;
		curr = curr->next;
	}
	return (average_path_steps + leftovers);
}

void	print_steps(t_path **paths, int steps)
{
	t_ant	*head;
	t_path	*curr;
	int		ant_nb;

	ant_nb = 1;
	head = NULL;
	while (--steps > 0)
	{
		curr = *paths;
		while (curr != NULL)
		{
			if (curr->assign_ants > 0)
			{
				head = add_ant(ant_nb, curr, head);
				ant_nb++;
				curr->assign_ants--;
			}
			curr = curr->next;
		}
		print_curr_list(head);
	}
	free_ants_list(head);
}

t_ant	*add_ant(int nb, t_path *path, t_ant *head)
{
	t_ant	*new;
	t_ant	*curr;

	curr = head;
	new = (t_ant*)ft_memalloc(sizeof(t_ant));
	new->nb = nb;
	new->path = path;
	new->next = NULL;
	new->at_end = 0;
	new->pos = 0;
	if (curr != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
	else
		head = new;
	return (head);
}

void	print_curr_list(t_ant *head)
{
	t_ant	*curr;
	t_ant	*prev;

	curr = head;
	prev = NULL;
	while (curr != NULL)
	{
		if (!curr->at_end)
		{
			print_format(curr->nb, curr->path->steps[curr->pos]->name);
			curr->pos += 1;
			if (curr->pos == curr->path->len)
				curr->at_end = 1;
			if (prev != NULL)
				if (prev->at_end || curr->next != NULL)
					ft_putchar(' ');
			if (prev == NULL)
				ft_putchar(' ');
		}
		prev = curr;
		curr = curr->next;
	}
	ft_putchar('\n');
}

void	print_format(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
}
