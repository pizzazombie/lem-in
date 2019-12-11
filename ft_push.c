/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:29:19 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_push_back(t_room *begin, t_room *new)
{
	t_room	*p;

	p = begin;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

void	ft_push_front(t_room *new, t_all *all)
{
	t_room	*p;

	p = all->list;
	new->next = p;
	all->list = new;
}
