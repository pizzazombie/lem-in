/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 18:49:12 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_check_coordi(char *line)
{
	int i;
	int w;

	w = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			w = 1;
		if (line[i] == ' ' && w == 1)
			break ;
		if (line[i] == '-')
			ft_error();
		i++;
	}
	ft_my_atoi(line + i);
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	ft_my_atoi(line + i);
}

static int	my_flow(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int			ft_my_atoi(const char *str)
{
	int					i;
	int					c;
	unsigned long long	b;
	int					k;

	b = 0;
	k = 1;
	i = my_flow(str);
	if (str[i] == '-')
	{
		i++;
		k = -1;
	}
	else if (str[i] == '+')
		i++;
	while ((c = str[i++]) > 47 && c < 58)
	{
		b = b * 10 + (c + 2) % 10;
		if (b >= 2147483648 && k == 1)
			ft_error();
		else if (b > 2147483648 && k == -1)
			ft_error();
	}
	return (b * k);
}
