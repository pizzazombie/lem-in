/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 15:49:40 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_store_path(t_all *all)
{
	t_path *new;

	new = (t_path*)malloc(sizeof(t_path));
	new->l_path = all->l_path;
	new->short_path = all->short_path;
	new->next = NULL;
	new->num_ants = 0;
	new->num_ants1 = 0;
	if (all->list_path == NULL)
		all->list_path = new;
	else
		ft_add_path_to_the_end(all, new);
}

void	ft_add_path_to_the_end(t_all *all, t_path *new)
{
	t_path	*p;

	p = all->list_path;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

void	ft_add_and_move_path(t_all *all, t_path *new)
{
	t_path *temp;
	t_path *before;

	if (all->list_path == NULL)
		all->list_path = new;
	else
	{
		temp = all->list_path;
		before = NULL;
		while (temp != NULL)
		{
			if (temp->l_path > new->l_path)
				return ;
			before = temp;
			temp = temp->next;
		}
		before->next = new;
	}
}
