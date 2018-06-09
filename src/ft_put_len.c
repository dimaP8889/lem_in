/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:17:54 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/10 00:19:06 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_len(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	//ft_printf("room: %i\n", count);
	room = mass_rooms[count]->r_name;
	if (len < mass_rooms[count]->length || !mass_rooms[count]->length)
	{
		mass_rooms[count]->length = len;
		mass_rooms[count]->length_cp = len;
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

void	ft_set_len_bk(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	//ft_printf("room: %i\n", count);
	room = mass_rooms[count]->r_name;
	if (len < mass_rooms[count]->length_bk || !mass_rooms[count]->length_bk)
	{
		mass_rooms[count]->length_bk = len;
		mass_rooms[count]->length_bk_cp = len;
		room->use_bk = 0;
	}
	if (room->use_bk)
		return;	
	while (room)
	{
		room->use_bk = 1;
		ft_set_len_bk(mass_rooms, room->num, len + 1);
		room = room->next;
	}
}

int		ft_find_start(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->start)
		count++;
	return (count);
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
	int count_fin;
	t_room **mass_rooms;

	mass_rooms = mass_rooms_cp;
	count = ft_find_start(mass_rooms);
	count_fin = ft_find_finish(mass_rooms);
	ft_set_len(mass_rooms, count, 0);
	ft_set_len_bk(mass_rooms, count_fin, 0);
	mass_rooms[count]->length = 0;
	mass_rooms[count]->length_cp = 0;
	mass_rooms[count_fin]->length_bk = 0;
	mass_rooms[count_fin]->length_bk_cp = 0;
}