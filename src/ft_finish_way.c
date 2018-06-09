/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 01:23:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/10 01:41:34 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_do_way_bk(t_room **mass_rooms, int count, int len)
{
	t_name *room;
	static	int	coun;

	while (!mass_rooms[count]->fin)
	{
		room = mass_rooms[count]->r_name;
		mass_rooms[count]->left_way = 1;
		while (room && (!mass_rooms[room->num]->use_bk 
		|| mass_rooms[room->num]->length_bk_cp > len 
		|| mass_rooms[room->num]->left_way))
			room = room->next;
		if (!room)
		{
			if (!len && !coun)
				ft_exit();
			return;
		}
		len--;
		count = room->num;
	}
	coun++;
}


void	ft_make_way_bk(t_room **mass_rooms, int len)
{
	int		count;
	int		num;

	count = 0;
	num = 0;
	while (num <= len)
	{
		while (mass_rooms[count])
		{
			if (mass_rooms[count]->length_bk_cp == num)
			{
				mass_rooms[count]->use_bk = 1;
				if (mass_rooms[count]->start)
				{
					ft_do_way_bk(mass_rooms, count, num);
					return;
				}
			}
			count++;
		}
		count = 0;
		num++;
	}
}

void	ft_set_length_bk(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	room = mass_rooms[count]->r_name;
	mass_rooms[count]->use_bk = 0;
	if ((len < mass_rooms[count]->length_bk_cp 
		|| !mass_rooms[count]->length_bk_cp) 
		&& !mass_rooms[count]->fin)
	{
		mass_rooms[count]->length_bk_cp = len;
		room->use_bk = 0;
	}
	if (room->use_bk == 1)
		return;
	while (room)
	{
		while (room && (mass_rooms[room->num]->left_way))
			room = room->next;
		if (!room)
			return;
		room->use_bk = 1;
		ft_set_length_bk(mass_rooms, room->num, len + 1);
		room = room->next;
	}
}


void	ft_use_null_bk(t_room **mass_rooms)
{
	int	count;
	t_name *room;

	count = 0;
	while (mass_rooms[count])
	{
		mass_rooms[count]->length_bk_cp = 0;
		room = mass_rooms[count]->r_name;
		while (room)
		{
			room->use_bk = 0;
			room = room->next;
		}
		count++;
	}
}

void	ft_finish_way(t_room **mass_rooms, int start, int fin, int count_ways)
{
	int		len;

	while (count_ways)
	{
		len = ft_find_len_bk(mass_rooms);
		ft_make_way_bk(mass_rooms, len);
		mass_rooms[fin]->left_way = 0;
		ft_use_null_bk(mass_rooms);
		ft_set_length_bk(mass_rooms, fin, 0);
		count_ways--;
	}
	mass_rooms[start]->left_way = 1;
	mass_rooms[fin]->left_way = 1;
}
