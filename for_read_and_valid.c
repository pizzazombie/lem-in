/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_read_and_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 19:30:15 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_comment(char *line, t_all *all)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (all->end == 1)
			ft_error();
		if (all->file == 0)
			ft_error();
		if (all->start == 0)
			all->start = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (all->start == 1)
			ft_error();
		if (all->file == 0)
			ft_error();
		if (all->end == 0)
			all->end = 1;
	}
}

void	ft_check_name_room(char *line)
{
	if (line[0] == 'L')
		ft_error();
	ft_check_coordi(line);
}

void	ft_read_start(char *line, t_all *all)
{
	all->start = 2;
	all->s = all->list;
}

void	ft_read_end(char *line, t_all *all)
{
	all->end = 2;
	all->e = all->list;
}
