/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:42:47 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:45:48 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_same_coord(t_room *room, t_room **mass_rooms, int coord)
{
	int		count;

	count = 0;
	while (mass_rooms[count])
	{
		if ((room->x == mass_rooms[count]->x && room->y == mass_rooms[count]->y)
		|| !ft_strcmp(room->name, mass_rooms[count]->name))
			if (count != coord)
				ft_exit();
		count++;
	}
}

void	ft_check_rights(t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (mass_rooms[count])
	{
		ft_check_same_coord(mass_rooms[count], mass_rooms, count);
		count++;
	}
}
