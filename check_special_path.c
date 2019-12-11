/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 18:50:52 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_special(t_all *all)
{
	t_path *temp;

	temp = all->list_path;
	while (temp != NULL)
	{
		if (ft_check_paths(temp, all) == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_check_paths(t_path *temp, t_all *all)
{
	int i;
	int j;

	i = 1;
	while (i < temp->l_path - 1)
	{
		j = 1;
		while (j < all->l_path - 1)
		{
			if (temp->short_path[i] == all->short_path[j])
			{
				if (ft_find_around(temp, i, all, j) == 0)
				{
					ft_delete_link(all, j);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_find_around(t_path *temp, int i, t_all *all, int j)
{
	t_room *t1;
	t_room *t2;
	t_room *c1;
	t_room *c2;

	t1 = temp->short_path[i - 1];
	t2 = temp->short_path[i + 1];
	c1 = all->short_path[j - 1];
	c2 = all->short_path[j + 1];
	if (t1 == c1 || t1 == c2 || t2 == c1 || t2 == c2)
		return (1);
	return (0);
}

void	ft_delete_link(t_all *all, int i)
{
	ft_bun_link(all->short_path[i - 1], all->short_path[i]);
	ft_bun_link(all->short_path[i], all->short_path[i - 1]);
}
