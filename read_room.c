/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:29:09 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_type_of_line(char *line, t_all *all)
{
	char	**mass;
	int		i;

	i = ft_sum_w(line, ' ');
	if (i == 3)
		return (0);
	else if (i != 1 || ft_strchr(line, '-') == NULL)
		ft_error();
	else
	{
		all->links = 1;
		if (all->start != 2 || all->end != 2)
			ft_error();
		ft_read_link(line, all);
	}
	return (1);
}

void	ft_read_room(char *line, t_all *all)
{
	t_room	*new;
	char	*name;
	int		k;

	ft_check_name_room(line);
	name = ft_write_name(line);
	if (ft_check_qcual_room(all, name) == 0)
	{
		ft_strdel(&name);
		return ;
	}
	new = (t_room*)malloc(sizeof(t_room));
	new->next = NULL;
	new->num_neib = 0;
	new->kg = -1;
	new->mur = -1;
	new->neib = NULL;
	new->mass = NULL;
	new->name = name;
	new->name_with_coord = ft_strdup(line);
	ft_push_front(new, all);
	if ((k = ft_strlen(name)) > all->max_name)
		all->max_name = k;
}

int		ft_check_qcual_room(t_all *all, char *name)
{
	t_room *temp;

	temp = all->list;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, name) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_room	*ft_find_room(char *name, t_all *all)
{
	t_room	*p;

	p = all->list;
	while (p != NULL)
	{
		if (ft_strcmp(name, p->name) == 0)
			return (p);
		p = p->next;
	}
	ft_error();
	return (NULL);
}

char	*ft_write_name(char *line)
{
	int		i;
	int		w;
	char	*name;
	int		j;

	w = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			w = 1;
		if (line[i] == ' ' && w == 1)
			break ;
		i++;
	}
	name = (char*)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		name[j] = line[j];
		j++;
	}
	name[i] = '\0';
	return (name);
}
