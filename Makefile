# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 17:02:34 by dpogrebn          #+#    #+#              #
#    Updated: 2018/06/10 19:32:37 by dmitriy1         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 NAME = ./lem-in
LIBA = libft/libft.a
SRC = src/ft_valid.c src/lem_in.c src/ft_make_links.c src/ft_make_graph.c src/ft_put_len.c \
src/ft_find_ways.c src/ft_start_way.c src/ft_finish_way.c src/ft_find_len.c src/ft_move_ants.c
HEADER = src/lem_in.h
FLAGS = -Wall -Wextra -Werror
CC = gcc

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA)