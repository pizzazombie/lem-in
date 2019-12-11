/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:22:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_file(t_all *all)
{
	char	*line;
	t_room	*p;
	t_file	*end;

	line = NULL;
	end = all->doc;
	while (get_next_line(all->fd, &line) > 0)
	{
		ft_check_line(line, all);
		if (all->doc == NULL)
		{
			all->doc = ft_end_file(line);
			end = all->doc;
		}
		else
		{
			end->next = ft_end_file(line);
			end = end->next;
		}
	}
	ft_strdel(&line);
	if (all->link == NULL)
		ft_error();
}

t_file	*ft_end_file(char *line)
{
	t_file *new;

	new = (t_file*)malloc(sizeof(t_file));
	new->next = NULL;
	new->line = line;
	return (new);
}

void	ft_check_line(char *line, t_all *all)
{
	if (all->file == 0)
		ft_check_number(line, all);
	else
		ft_check_type(line, all);
}

void	ft_check_number(char *line, t_all *all)
{
	if (ft_strncmp(line, "#", 1) == 0)
	{
		ft_check_comment(line, all);
		return ;
	}
	else if (ft_str_is_digit(line) == 0)
		ft_error();
	all->ants = ft_atoi(line);
	if (all->ants <= 0)
		ft_error();
	else
		all->file = 1;
}

void	ft_check_type(char *line, t_all *all)
{
	if (ft_strncmp(line, "#", 1) == 0)
		ft_check_comment(line, all);
	else if (all->links == 0)
	{
		if (ft_check_type_of_line(line, all) == 1)
			return ;
		ft_read_room(line, all);
		if (all->start == 1)
			ft_read_start(line, all);
		else if (all->end == 1)
			ft_read_end(line, all);
	}
	else
		ft_read_link(line, all);
}
