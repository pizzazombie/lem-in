/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 19:15:23 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_make_graph(t_all *all)
{
	t_room *temp;

	temp = all->list;
	while (temp != NULL)
	{
		temp->neib = (t_ube**)malloc(sizeof(t_ube*) * temp->num_neib);
		ft_make_neib(all, temp);
		temp = temp->next;
	}
}

void	ft_make_neib(t_all *all, t_room *now)
{
	char	*name;
	t_room	*temp;
	t_room	*find;
	int		i;

	i = 0;
	name = now->name;
	temp = all->link;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->mass[0], name) == 0)
		{
			ft_create_tube(all, temp->mass[1], now, i);
			i++;
		}
		else if (ft_strcmp(temp->mass[1], name) == 0)
		{
			ft_create_tube(all, temp->mass[0], now, i);
			i++;
		}
		temp = temp->next;
	}
}

void	ft_create_tube(t_all *all, char *forfind, t_room *now, int i)
{
	t_room	*find;

	find = ft_find_room(forfind, all);
	now->neib[i] = (t_ube*)malloc(sizeof(t_ube));
	now->neib[i]->neib = find;
	now->neib[i]->w = 1;
	now->neib[i]->f = 1;
}
