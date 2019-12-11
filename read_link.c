/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:28:40 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_link(char *line, t_all *all)
{
	t_room	*new;
	char	**mass;

	mass = ft_check_name_of_rooms(line, all);
	if (ft_check_equal_link(all, line, mass) == 0)
		return ;
	ft_add_neib(all, mass);
	new = (t_room*)malloc(sizeof(t_room));
	new->next = NULL;
	new->neib = NULL;
	new->mass = mass;
	new->name = ft_strdup(line);
	new->name_with_coord = NULL;
	if (all->link == NULL)
		all->link = new;
	else
		ft_push_back(all->link, new);
}

void	ft_add_neib(t_all *all, char **two)
{
	t_room	*p;

	p = ft_find_room(two[0], all);
	p->num_neib++;
	p = ft_find_room(two[1], all);
	p->num_neib++;
}

int		ft_check_equal_link(t_all *all, char *line, char **mass)
{
	t_room	*temp;
	char	*rev;

	temp = all->link;
	rev = ft_check_rev_link(mass);
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, line) == 0 || ft_strcmp(temp->name, rev) == 0)
		{
			ft_strdel(&rev);
			ft_strdel(&mass[0]);
			ft_strdel(&mass[1]);
			free(mass);
			return (0);
		}
		temp = temp->next;
	}
	ft_strdel(&rev);
	return (1);
}

char	*ft_check_rev_link(char **mass)
{
	char	*temp;
	char	*ans;

	temp = ft_strjoin(mass[1], "-");
	ans = ft_strjoin(temp, mass[0]);
	ft_strdel(&temp);
	return (ans);
}

char	**ft_check_name_of_rooms(char *line, t_all *all)
{
	char	**two;
	t_room	*p;
	int		i;
	char	*z;

	i = 0;
	z = ft_strchr(line, '-');
	if (z == NULL)
		ft_error();
	two = (char**)malloc(sizeof(char*) * 3);
	two[1] = ft_strdup(z + 1);
	z[0] = '\0';
	two[0] = ft_strdup(line);
	z[0] = '-';
	two[2] = NULL;
	while (two[i] != NULL)
		i++;
	return (two);
}
