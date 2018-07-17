/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:48:36 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_mass(t_room **mass_room)
{
	int		count;
	t_name	*name;

	count = 0;
	while (mass_room[count])
	{
		while (mass_room[count]->r_name)
		{
			name = mass_room[count]->r_name;
			mass_room[count]->r_name = mass_room[count]->r_name->next;
			free(name);
		}
		free(mass_room[count]->name);
		free(mass_room[count]->next_room);
		free(mass_room[count]);
		count++;
	}
	free(mass_room);
}

int		main(void)
{
	t_room	**mass_room;
	int		fd;
	int		ants;

	fd = open("src/read", O_RDONLY);
	ants = ft_check_num(0);
	mass_room = ft_valid(0);
	ft_move_ants(ants, mass_room);
	ft_free_mass(mass_room);
}
