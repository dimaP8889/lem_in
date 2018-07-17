/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:56:38 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_links(t_room *rooms)
{
	int		count;

	count = 0;
	while (rooms)
	{
		rooms = rooms->next_room;
		count++;
	}
	return (count);
}

int		ft_check_num(int fd)
{
	char			*str;
	long int		ants;
	int				cnt;

	ants = 0;
	cnt = get_next_line(fd, &str);
	ft_printf("%s\n", str);
	if (cnt < 1)
		ft_exit();
	while (str[0] == '#' && (ft_strcmp(str, "##start"))
	&& (ft_strcmp(str, "##end")))
	{
		free(str);
		get_next_line(fd, &str);
		ft_printf("%s\n", str);
	}
	ants = ft_atoi(str);
	ft_check_digit(str);
	if (ants <= 0 || ants > 2147483647)
		ft_exit();
	free(str);
	return (ants);
}

t_room	**ft_set_params(t_room **mass_rooms)
{
	int		coun;

	coun = 0;
	while (mass_rooms[coun])
	{
		mass_rooms[coun]->next_room = NULL;
		mass_rooms[coun]->free = 1;
		mass_rooms[coun]->ants = 0;
		mass_rooms[coun]->left_way = 0;
		mass_rooms[coun]->use_bk = 0;
		mass_rooms[coun]->length_bk = 0;
		coun++;
	}
	return (mass_rooms);
}

t_room	**ft_make_mass(t_room **mass_rooms, t_room *in)
{
	int		coun;

	coun = 0;
	while (in->next_room)
	{
		mass_rooms[coun] = (t_room *)malloc(sizeof(t_room));
		mass_rooms[coun]->name = ft_strdup(in->name);
		mass_rooms[coun]->x = in->x;
		mass_rooms[coun]->y = in->y;
		mass_rooms[coun]->r_name = NULL;
		mass_rooms[coun]->start = in->start;
		mass_rooms[coun]->fin = in->fin;
		free(in->name);
		free(in);
		in = in->next_room;
		coun++;
	}
	free(in);
	mass_rooms[coun] = NULL;
	return (mass_rooms);
}

t_room	**ft_valid(int fd)
{
	t_room	**mass_rooms;
	t_room	*in;
	int		coun;
	char	*str;

	in = NULL;
	str = NULL;
	coun = 0;
	in = ft_check_rooms(in, fd, &str);
	mass_rooms = (t_room **)malloc(sizeof(t_room *) * ft_count_links(in));
	mass_rooms = ft_make_mass(mass_rooms, in);
	mass_rooms = ft_set_params(mass_rooms);
	ft_check_rights(mass_rooms);
	ft_make_links(mass_rooms, fd, str);
	return (mass_rooms);
}
