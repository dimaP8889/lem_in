/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/12 14:34:59 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_lem	*in;
	int		fd;

	in = (t_lem *)malloc(sizeof(t_lem));
	fd = open("src/read", O_RDONLY);
	in->rooms = ft_valid(in, fd);
	ft_move_ants(in->num_ants, in->rooms);
	//ft_print_room(in->rooms);
}