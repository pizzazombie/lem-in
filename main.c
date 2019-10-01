/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/10/01 18:13:15 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void	ft_process_input(t_m *map);
{

}

void	ft_init_all(t_m *map, t_all *all)
{
	char buf[BUFF_SIZE + 1];
	char *temp;
	int r;
	
	map->in = ft_strnew(1);
	all->rooms = 0;
	while ((r = read(0, &buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		temp = map->in;
		map->in = ft_strjoin(map->in, buf);
		ft_strdel(&temp);
	}
	//map->rooms = 0;
	ft_process_input(map);
	
}

int main(int ac, char **av)
{
	int i;
	t_m map;
	t_all all;
	
	if (ac == 2)
	{
		ft_init_all(&map, &all);
		printf("str = %s\n", map.in);
	}
	return (0);
}
