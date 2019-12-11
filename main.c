/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:03:54 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init(t_all *all)
{
	all->start = 0;
	all->end = 0;
	all->file = 0;
	all->rooms = 0;
	all->links = 0;
	all->list = NULL;
	all->link = NULL;
	all->s = NULL;
	all->e = NULL;
	all->list_path = NULL;
	all->num_path_for_alg = 0;
	all->i = 0;
	all->max_name = 4;
	all->fd = 0;
	all->doc = NULL;
}

int		ft_check_arg(int argc, char **argv)
{
	if (argc > 2)
		ft_usage();
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-i") == 0)
			return (1);
		ft_usage();
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		f;
	t_all	all;

	f = ft_check_arg(argc, argv);
	ft_init(&all);
	ft_read_file(&all);
	ft_make_graph(&all);
	if (all.e->num_neib == 0 || all.s->num_neib == 0)
	{
		write(1, "ERROR\n", 6);
		ft_del_all(&all);
		return (0);
	}
	ft_while_start(&all, 0);
	ft_come_back(&all);
	ft_while_start(&all, 1);
	ft_print_file(&all);
	ft_distribute_ants(&all);
	ft_output(&all);
	if (f == 1)
		ft_print_all(&all);
	ft_del_all(&all);
	return (0);
}
