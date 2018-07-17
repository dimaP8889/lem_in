/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:17:54 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/15 13:41:00 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_len_bk(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	room = mass_rooms[count]->r_name;
	if (len < mass_rooms[count]->length_bk || !mass_rooms[count]->length_bk)
	{
		mass_rooms[count]->length_bk = len;
		room->use_bk = 0;
	}
	if (room->use_bk)
	{
		return ;
	}
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
	{
		count++;
		if (!mass_rooms[count])
			ft_exit();
	}
	return (count);
}

int		ft_find_finish(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (!mass_rooms[count]->fin)
	{
		count++;
		if (!mass_rooms[count])
			ft_exit();
	}
	return (count);
}

void	ft_put_len(t_room **mass_rooms_cp)
{
	int		count_fin;
	int		start;
	t_room	**mass_rooms;

	
	mass_rooms = mass_rooms_cp;
	start = ft_find_start(mass_rooms);
	count_fin = ft_find_finish(mass_rooms);
	if (!mass_rooms[count_fin]->r_name || !mass_rooms[start]->r_name)
	{
		ft_exit();
	}
	ft_set_len_bk(mass_rooms, count_fin, 0);
	mass_rooms[count_fin]->length_bk = 0;
}
