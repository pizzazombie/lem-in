/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_warning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:25:15 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_usage(void)
{
	ft_printf("\033[33;1;4mUsage\033[0m : ./lem-in [-i] < <filename>\n");
	exit(1);
}

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

void	ft_print_file(t_all *all)
{
	t_file *temp;
	t_file *del;

	temp = all->doc;
	while (temp != NULL)
	{
		ft_putstr(temp->line);
		write(1, "\n", 1);
		ft_strdel(&temp->line);
		del = temp;
		temp = temp->next;
		free(del);
	}
}
