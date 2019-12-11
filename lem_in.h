/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:17:28 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct		s_ube
{
	int				w;
	int				f;
	struct s_room	*neib;
}					t_ube;

typedef struct		s_room
{
	int				mur;
	char			*name;
	char			*name_with_coord;
	int				kg;
	int				num_neib;
	char			**mass;
	struct s_room	*next;
	t_ube			**neib;
}					t_room;

typedef struct		s_path
{
	int				l_path;
	t_room			**short_path;
	int				num_ants;
	int				num_ants1;
	struct s_path	*next;
}					t_path;

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_all
{
	int				ants;
	int				start;
	t_room			*s;
	t_room			*e;
	int				end;
	int				file;
	int				rooms;
	int				links;
	int				fd;
	int				i;
	int				l_path;
	int				num_path_for_alg;
	int				max_name;
	t_file			*doc;
	t_room			*list;
	t_room			*link;
	t_path			*list_path;
	t_room			**short_path;
}					t_all;

void				ft_usage();
void				ft_read_file(t_all *all);
void				ft_init(t_all *all);
void				ft_check_line(char *line, t_all *all);
void				ft_check_number(char *line, t_all *all);
void				ft_check_comment(char *line, t_all *all);
void				ft_check_name_room(char *line);
void				ft_check_type(char *line, t_all *all);
int					ft_check_type_of_line(char *line, t_all *all);
char				**ft_check_name_of_rooms(char *line, t_all *all);
void				ft_read_end(char *line, t_all *all);
void				ft_read_start(char *line, t_all *all);
void				ft_read_room(char *line, t_all *all);
void				ft_read_link(char *line, t_all *all);
void				ft_push_back(t_room *begin, t_room *new);
void				ft_push_front(t_room *new, t_all *all);
t_room				*ft_find_room(char *name, t_all *all);
char				*ft_write_name(char *line);
void				ft_make_graph(t_all *all);
void				ft_make_neib(t_all *all, t_room *now);
void				ft_print_all(t_all *all);
void				ft_print_neib(t_room *p);
void				ft_print_all_path(t_all *all);
void				ft_print_file(t_all *all);
void				ft_del_all(t_all *all);
void				ft_clean_rooms(t_all *all);
void				ft_clean_link(t_all *all);
void				ft_clean_list_path(t_all *all);
void				ft_list_print(t_room *temp);
int					kg_rec(t_room *room, int kg);
void				ft_find_short_path(t_all *all);
t_room				*ft_find_prev(t_room *temp, int kg, t_room *not_this);
void				ft_print_path(t_room **path);
int					ft_my_atoi(const char *str);
void				ft_check_coordi(char *line);
void				ft_while_start(t_all *all, int k);
int					ft_have_link(t_room *start);
void				ft_make_kg_zero(t_room *temp);
void				ft_return_link(t_all *all);
void				ft_bun_link(t_room *room, t_room *neib);
void				ft_change_w(t_room *neib, t_room *room, int nw);
int					ft_check_link(t_room *room, t_room *neib);
int					ft_count_l(t_all *all);
void				ft_come_back(t_all *all);
void				ft_find_one_side_link(t_room *room);
void				ft_store_path(t_all *all);
void				ft_add_path_to_the_end(t_all *all, t_path *new);
void				ft_print_file(t_all *all);
t_file				*ft_end_file(char *line);
void				ft_distribute_ants(t_all *all);
void				ft_output(t_all *all);
void				ft_process_path(t_all *all, t_path *path);
void				ft_move_ants(t_path *path);
void				ft_add_ants(t_all *all, t_path *path);
int					ft_check_equal_link(t_all *all, char *line, char **mass);
char				*ft_check_rev_link(char **mass);
void				ft_add_neib(t_all *all, char **two);
int					ft_check_qcual_room(t_all *all, char *name);
int					ft_check_special(t_all *all);
int					ft_check_paths(t_path *temp, t_all *all);
int					ft_find_around(t_path *temp, int i, t_all *all, int j);
void				ft_delete_link(t_all *all, int i);
void				ft_error();
void				ft_distribute_ants_double(t_all *all, t_path *temp);
void				ft_create_tube(t_all *all,
		char *forfind, t_room *now, int i);
void				ft_while_start_son(t_all *all, int k);

#endif
