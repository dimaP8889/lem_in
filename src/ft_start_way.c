/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 01:23:06 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/12 15:32:18 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_do_way(t_room **mass_rooms, int count, int len)
{
	t_name *room;
	static	int	coun;

	while (!mass_rooms[count]->start)
	{
		room = mass_rooms[count]->r_name;
		mass_rooms[count]->right_way = 1;
		while (room && (!mass_rooms[room->num]->use
		|| mass_rooms[room->num]->length_cp > len 
		|| mass_rooms[room->num]->right_way))
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

void	ft_make_way(t_room **mass_rooms, int len)
{
	int		count;
	int		num;

	count = 0;
	num = 0;
	while (num <= len)
	{
		while (mass_rooms[count])
		{
			if (mass_rooms[count]->length_cp == num)
			{
				mass_rooms[count]->use = 1;
				if (mass_rooms[count]->fin)
				{
					ft_do_way(mass_rooms, count, num);
					return;
				}
			}
			count++;
		}
		count = 0;
		num++;
	}
}

void	ft_set_length(t_room **mass_rooms, int count, int len)
{
	t_name *room;

	room = mass_rooms[count]->r_name;
	mass_rooms[count]->use = 0;
	if ((len < mass_rooms[count]->length_cp || !mass_rooms[count]->length_cp) 
		&& !mass_rooms[count]->start)
	{
		mass_rooms[count]->length_cp = len;
		room->use = 0;
	}
	if (room->use)
	{
		return;
	}
	while (room)
	{
		while (room && mass_rooms[room->num]->right_way /*&& room->use*/)
			room = room->next;
		if (!room)
		{
			return;
		}
		room->use = 1;
		ft_set_length(mass_rooms, room->num, len + 1);
		room = room->next;
	}
}

void	ft_use_null(t_room **mass_rooms)
{
	int	count;
	t_name *room;

	count = 0;
	while (mass_rooms[count])
	{
		mass_rooms[count]->length_cp = 0;
		room = mass_rooms[count]->r_name;
		while (room)
		{
			room->use = 0;
			room = room->next;
		}
		count++;
	}
}

void	ft_start_way(t_room **mass_rooms, int start, int fin, int count_ways)
{
	int		len;

	while (count_ways)
	{
		len = ft_find_len(mass_rooms);
		ft_make_way(mass_rooms, len);
		mass_rooms[fin]->right_way = 0;
		ft_use_null(mass_rooms);
		ft_set_length(mass_rooms, start, 0);
		count_ways--;
	}
	mass_rooms[start]->right_way = 1;
	mass_rooms[fin]->right_way = 1;
}