/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:17:54 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/06 20:45:17 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_len(t_room **mass_rooms, int count, int len)
{
	static	int	chng;
	t_name *room;

	room = mass_rooms[count]->r_name;
	if (len < mass_rooms[count]->length || !mass_rooms[count]->length)
	{
		mass_rooms[count]->length = len;
		room->use = 0;
	}
	if (mass_rooms[count]->start)
		chng = 0;
	if (mass_rooms[count]->fin)
		chng = 1;
	if (room->use)
		return;	
	while (room)
	{
		mass_rooms[count]->right_way = chng;
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
	return (count);
}

void	ft_put_len(t_room **mass_rooms_cp)
{
	int	count;
	t_room **mass_rooms;

	mass_rooms = mass_rooms_cp;
	count = ft_find_finish(mass_rooms);
	ft_set_len(mass_rooms, count, 0);
	mass_rooms[count]->length = 0;
}