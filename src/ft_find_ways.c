/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:28:50 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/06 12:34:37 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_start(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->start)
		count++;
	return (count);
}

void	ft_get_ways(t_room **mass_rooms, int count)
{
	t_name *room;

	room = mass_rooms[count]->r_name;
	if (!room->use)
	{
		if (!room->next->use)
			mass_rooms[count]->right_way = 0;
		return;
	}
	while (room)
	{
		room->use = 0;
		ft_get_ways(mass_rooms, room->num);
		room = room->next;
	}
}

void	ft_find_ways(t_room **mass_rooms)
{
	int		count;

	count = ft_find_start(mass_rooms);
	ft_get_ways(mass_rooms, count);
}
