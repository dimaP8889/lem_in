/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:16:55 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/15 13:36:52 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define COUNT	mass_rooms[count]->r_name
#define F_S		mass_rooms[f_s]->r_name

#include "lem_in.h"

t_name		*ft_make_first(int count)
{
	t_name	*name;

	name = (t_name *)malloc(sizeof(t_name));
	name->use = 0;
	name->use_bk = 0;
	name->last = 0;
	name->num = count;
	name->next = NULL;
	return (name);
}

t_name		*ft_make_r_name(t_name *r_name, int f_s)
{
	t_name *r_name_cp;

	if (!r_name)
	{
		r_name = ft_make_first(f_s);
		r_name_cp = r_name;
		return (r_name_cp);
	}
	r_name_cp = r_name;
	while (r_name->next)
		r_name = r_name->next;
	r_name->next = ft_make_first(f_s);
	return (r_name_cp);
}

void		ft_connect(t_room **mass_rooms_cp, t_links *links, int count)
{
	int		f_s;
	t_room	**mass_rooms;

	f_s = 0;
	mass_rooms = mass_rooms_cp;
	while (mass_rooms[count])
	{
		if (!ft_strcmp(mass_rooms[count]->name, links->f_name))
		{
			while (mass_rooms[f_s])
			{
				if (!ft_strcmp(mass_rooms[f_s]->name, links->s_name))
				{
					COUNT = ft_make_r_name(COUNT, f_s);
					F_S = ft_make_r_name(F_S, count);
				}
				f_s++;
			}
		}
		f_s = 0;
		count++;
	}
}

void		ft_make_graph(t_room **mass_rooms, t_links *links)
{
	while (links)
	{
		ft_connect(mass_rooms, links, 0);
		links = links->next;
	}
}
