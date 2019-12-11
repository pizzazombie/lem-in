/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_for_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:23:58 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_while_start(t_all *all, int k)
{
	while (ft_have_link(all->s) == 1 &&
			all->num_path_for_alg != all->e->num_neib)
	{
		ft_make_kg_zero(all->list);
		kg_rec(all->s, 0);
		ft_find_short_path(all);
		if (all->short_path == NULL)
			break ;
		if (k == 0 && ft_check_special(all) == 1)
		{
			free(all->short_path);
			all->short_path = NULL;
			all->num_path_for_alg--;
			continue;
		}
		ft_return_link(all);
		ft_store_path(all);
		all->short_path = NULL;
	}
	ft_while_start_son(all, k);
}

void	ft_while_start_son(t_all *all, int k)
{
	if (k == 0)
	{
		ft_clean_list_path(all);
		all->list_path = NULL;
	}
	if (all->num_path_for_alg == 0)
		ft_error();
	else
		all->num_path_for_alg = 0;
}

int		ft_have_link(t_room *start)
{
	int i;

	i = 0;
	while (i < start->num_neib)
	{
		if (start->neib[i]->f == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_make_kg_zero(t_room *temp)
{
	while (temp != NULL)
	{
		temp->kg = -1;
		temp = temp->next;
	}
}
