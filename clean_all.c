/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 18:52:43 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_del_all(t_all *all)
{
	t_room	*p;
	t_room	*temp;

	ft_clean_rooms(all);
	all->list = NULL;
	ft_clean_link(all);
	all->link = NULL;
	ft_clean_list_path(all);
}

void	ft_clean_rooms(t_all *all)
{
	t_room	*p;
	t_room	*temp;
	int		i;

	p = all->list;
	while (p != NULL)
	{
		i = 0;
		while (i < p->num_neib)
		{
			free(p->neib[i]);
			i++;
		}
		free(p->neib);
		ft_strdel(&p->name);
		ft_strdel(&p->name_with_coord);
		temp = p;
		p = p->next;
		free(temp);
	}
}

void	ft_clean_link(t_all *all)
{
	t_room	*p;
	t_room	*temp;
	int		i;

	p = all->link;
	while (p != NULL)
	{
		ft_strdel(&p->name);
		i = 0;
		while (p->mass[i] != NULL)
		{
			ft_strdel(&p->mass[i]);
			i++;
		}
		free(p->mass);
		temp = p;
		p = p->next;
		free(temp);
	}
}

void	ft_clean_list_path(t_all *all)
{
	t_path *temp;
	t_path *temp2;

	temp = all->list_path;
	while (temp != NULL)
	{
		free(temp->short_path);
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
