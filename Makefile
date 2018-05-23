# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 17:02:34 by dpogrebn          #+#    #+#              #
#    Updated: 2018/05/23 17:39:15 by dpogrebn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 NAME = ./lem-in
LIBA = libft/libft.a
SRC = src/ft_valid.c src/lem_in.c
HEADER = src/lem_in.h
FLAGS = -Wall -Wextra -Werror
CC = gcc

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA)