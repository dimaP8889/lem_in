/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:28:50 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/10 01:38:56 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_star(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->start)
		count++;
	return (count);
}

int		ft_find_fin(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->fin)
		count++;
	return (count);
}

int		ft_count_ways(t_room **mass_rooms, int count)
{
	int		num;
	t_name *room;

	room = mass_rooms[count]->r_name;
	num = 0;
	while (room)
	{
		num++;
		room = room->next;
	}
	return (num);
}

void	ft_find_ways(t_room **mass_rooms)
{
	int		start;
	int		fin;
	int		count_ways_start;
	int		count_ways_finish;

	start = ft_find_star(mass_rooms);
	fin = ft_find_fin(mass_rooms);
	count_ways_start = ft_count_ways(mass_rooms, fin);
	count_ways_finish = ft_count_ways(mass_rooms, start);
	ft_start_way(mass_rooms, start, fin, count_ways_start);
	ft_finish_way(mass_rooms, start, fin, count_ways_finish);
}
