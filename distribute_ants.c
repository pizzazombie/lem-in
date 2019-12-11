/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 19:06:01 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_distribute_ants(t_all *all)
{
	t_path	*temp;
	t_path	*temp2;
	int		i;

	temp = all->list_path;
	while (temp->next != NULL)
	{
		temp = temp->next;
		while (all->list_path->l_path + all->list_path->num_ants
				- 1 < temp->l_path)
		{
			temp2 = all->list_path;
			while (temp2 != temp)
			{
				temp2->num_ants++;
				temp2->num_ants1++;
				all->ants--;
				if (all->ants == 0)
					return ;
				temp2 = temp2->next;
			}
		}
	}
	ft_distribute_ants_double(all, temp);
}

void	ft_distribute_ants_double(t_all *all, t_path *temp)
{
	if (all->ants > 0)
	{
		temp->num_ants++;
		temp->num_ants1++;
		all->ants--;
	}
	while (all->ants > 0)
	{
		temp = all->list_path;
		while (temp != NULL)
		{
			temp->num_ants++;
			temp->num_ants1++;
			all->ants--;
			if (all->ants == 0)
				return ;
			temp = temp->next;
		}
	}
}
