# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2019/12/04 16:29:36 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH = ./Libft
LIBFT = $(LIBFTPATH)/libft.a

CFLAGS =  -I. -I$(LIBFTPATH) -Iinc -g3
CC = gcc

SRC = main.c put_warning.c read_file.c read_room.c for_read_and_valid.c make_graph.c \
		count_kg.c check_coordinate.c while_for_start.c store_path.c print_path.c \
		distribute_ants.c print_output.c check_special_path.c clean_all.c ft_while_start_son.c \
		ft_push.c read_link.c

OBJ = $(SRC:%.c=%.o)

NAME = lem-in

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ) 
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : ./lem_in.h

$(LIBFT) :
	make -C $(LIBFTPATH)

clean:
	make clean -C $(LIBFTPATH)
	rm -f $(OBJ) 

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
