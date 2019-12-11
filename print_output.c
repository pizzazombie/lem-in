/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 19:16:32 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_output(t_all *all)
{
	t_path	*temp;
	int		it;
	int		i;

	write(1, "\n", 1);
	it = all->list_path->l_path + all->list_path->num_ants - 2;
	i = 0;
	while (i < it)
	{
		temp = all->list_path;
		while (temp != NULL)
		{
			ft_process_path(all, temp);
			temp = temp->next;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_process_path(t_all *all, t_path *path)
{
	if (path->num_ants > 0)
	{
		ft_add_ants(all, path);
		path->num_ants--;
		ft_move_ants(path);
	}
	else
	{
		path->short_path[0]->mur = -1;
		ft_move_ants(path);
	}
}

void	ft_move_ants(t_path *path)
{
	int i;
	int temp;
	int temp2;

	i = path->l_path - 2;
	temp = path->short_path[i]->mur;
	while (i >= 0)
	{
		if (temp > 0)
			ft_printf("L%d-%s ", temp, path->short_path[i + 1]->name);
		path->short_path[i + 1]->mur = temp;
		i--;
		if (i >= 0)
			temp = path->short_path[i]->mur;
	}
}

void	ft_add_ants(t_all *all, t_path *path)
{
	all->i++;
	path->short_path[0]->mur = all->i;
}
