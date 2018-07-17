/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:10:00 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:18:46 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_find_next(t_name *room, t_room **mass_rooms, int count)
{
	int		num;

	num = 0;
	while (room)
	{
		if (mass_rooms[room->num]->left_way
		&& mass_rooms[room->num]->length_bk < mass_rooms[count]->length_bk)
		{
			num = room->num;
		}
		room = room->next;
	}
	return (num);
}

t_ants		*ft_make_ant(t_ants *ant, char *name)
{
	t_ants		*ant_cp;
	static int	ct;

	if (!ct)
		ct = 2;
	ant_cp = ant;
	while (ant->next)
	{
		ant = ant->next;
	}
	ant->next = (t_ants *)malloc(sizeof(t_ants));
	ant->next->name = name;
	ant->next->num = ct;
	ct++;
	ant->next->next = NULL;
	return (ant_cp);
}

t_ants		*ft_make_new(t_ants *ant, char *name)
{
	ant = (t_ants *)malloc(sizeof(t_ants));
	ant->name = name;
	ant->num = 1;
	ant->next = NULL;
	return (ant);
}

t_ants		*ft_start(t_room **mass_rooms, int count, int in, t_ants *ant)
{
	int start;
	int	finish;

	start = ft_find_start(mass_rooms);
	finish = ft_find_finish(mass_rooms);
	count = ft_find_next(mass_rooms[count]->r_name, mass_rooms, count);
	mass_rooms[count]->free = 0;
	mass_rooms[start]->ants--;
	if (!in)
		mass_rooms[finish]->ants++;
	if (mass_rooms[start]->ants >= 0)
	{
		if (!ant)
			ant = ft_make_new(ant, mass_rooms[count]->name);
		else
			ant = ft_make_ant(ant, mass_rooms[count]->name);
	}
	return (ant);
}
