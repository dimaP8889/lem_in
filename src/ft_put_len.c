/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:17:54 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/06 13:43:39 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_len(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	room = mass_rooms[count]->r_name;
	if (!room)
	{
		ft_printf("lol");
		return;
	}
	if (len < mass_rooms[count]->length || !mass_rooms[count]->length)
	{
		mass_rooms[count]->length = len;
		room->use = 0;
	}
	if (room->use)
		return;	
	while (room)
	{
		room->use = 1;
		ft_set_len(mass_rooms, room->num, len + 1);
		room = room->next;
	}
}

int		ft_find_finish(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->fin)
		count++;
	ft_printf("fin: %i\n", mass_rooms[count]->fin);
	return (count);
}

void	ft_put_len(t_room **mass_rooms_cp)
{
	int	count;
	t_room **mass_rooms;

	mass_rooms = mass_rooms_cp;
	count = ft_find_finish(mass_rooms);
	ft_printf("count :%i\n", count);
	ft_set_len(mass_rooms, count, 0);
	mass_rooms[count]->length = 0;
}