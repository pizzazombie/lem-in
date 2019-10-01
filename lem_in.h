/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:47 by mkami             #+#    #+#             */
/*   Updated: 2019/10/01 18:12:31 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

# include <stdio.h>
# include <stdlib.h>

# include <errno.h>


typedef struct		s_param
{
	char			*str;
	struct s_param	*next;
}					t_param;

typedef struct		s_m
{
	int				dudes;
	char			*in;
	char			*name;
	struct s_m	**next;
}					t_m;

typedef struct		s_all
{
	int				rooms;
}					t_all;

typedef struct		s_razriad
{
	int				links;
	int				user;
	int				size;
	int				day;
	int				half_year;
}					t_razriad;

#endif
