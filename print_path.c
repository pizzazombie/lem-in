/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:09:38 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_all(t_all *all)
{
	t_room	*p;

	ft_printf("KARAMBA!\n");
	ft_printf("\n\n\033[35;1;1m-_-_-_-_-_-_-_-_-_-");
	ft_printf("INFO -_-_-_-_-_-_-_-_-_-\033[0m\n\n");
	ft_printf("##START room is \033[36;1;1m%s\033[0m\n", all->s->name);
	ft_printf("##END room is \033[36;1;1m%s\033[0m\n\n", all->e->name);
	ft_printf("%-*s | %s | %s\n\n", all->max_name,
			"name", "num_neib", "neibour");
	p = all->list;
	while (p != NULL)
	{
		ft_printf("\033[32;1;1m%-*s\033[0m | ", all->max_name, p->name);
		ft_printf("\033[33;1;1m%-8d\033[0m | ", p->num_neib);
		ft_print_neib(p);
		p = p->next;
	}
	ft_print_all_path(all);
	write(1, "\nGood luck, bye!\n", 17);
	ft_printf("\033[35;1;1m-_-_-_-_-_-_-_-_-_-_-_-");
	ft_printf("_-_-_-_-_-_-_-_-_-_-\033[0m\n\n");
}

void	ft_print_neib(t_room *p)
{
	int i;

	i = 0;
	if (p->neib != NULL)
	{
		while (i < p->num_neib)
		{
			if (p->neib[i] != NULL)
			{
				ft_printf("\033[31;1;1m%s\033[0m", p->neib[i]->neib->name);
				if (i + 1 < p->num_neib)
					write(1, " - ", 3);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

void	ft_print_all_path(t_all *all)
{
	t_path	*temp;
	int		i;

	write(1, "\nAll paths:\n", 12);
	temp = all->list_path;
	while (temp != NULL)
	{
		i = 0;
		while (i < temp->l_path)
		{
			ft_printf("\033[33;1;1m%s\033[0m", temp->short_path[i]->name);
			if (i + 1 < temp->l_path)
				write(1, " -> ", 4);
			i++;
		}
		ft_printf(" | ants\033[47m\xf0\x9f\x90\x9c \033[47m\xf0\x9f\x90\x9c");
		ft_printf(" \033[47m\xf0\x9f\x90\x9c");
		ft_printf(" \033[0m = \033[34;1;1m%d\033[0m | ", temp->num_ants1);
		ft_printf("rooms = \033[35;1;1m%d\033[0m\n", temp->l_path);
		temp = temp->next;
	}
}
