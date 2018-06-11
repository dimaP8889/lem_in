/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/10 13:38:42 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit()
{
	ft_printf("ERROR\n");
	exit(1);
}

void	ft_comment(char **str, int fd, t_room *room)
{
	static int	start;
	static int	fin;

	while (*str[0] == '#' && (ft_strcmp(*str, "##start")) 
	&& (ft_strcmp(*str, "##end")))
		get_next_line(fd, str);
	if (!ft_strcmp(*str, "##start"))
	{
		start++;
		(room)->start = 1;
		get_next_line(fd, str);
	}
	else
		(room)->start = 0;
	if (!ft_strcmp(*str, "##end"))
	{
		fin++;
		(room)->fin = 1;
		get_next_line(fd, str);
	}
	else
		(room)->fin = 0;
	if (start > 1|| fin > 1)
		ft_exit();
	*str[0] == '#' ? ft_comment(str, fd, (room)) : *str[0] == '#';
}

int		ft_mass_len(char **mass)
{
	int		len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}


void	ft_check_digit(char *str)
{
	int	num;

	num = 0;
	while (str[num])
	{
		if (!ft_isdigit(str[num]))
			ft_exit();
		num++;
	}
}

void	ft_check_name(char *str)
{
	if (str[0] == 'L' || ft_strstr(str, "-"))
	{
		ft_exit();
	}
}

void		ft_valid_room(char *str, int fd, t_room *room)
{
	char	**params;

	room->fin = 0;
	room->start = 0;
	if (str[0] == '#')
		ft_comment(&str, fd, room);
	params = ft_strsplit(str, ' ');
	if (ft_mass_len(params) != 3 || !ft_strlen(str))
		ft_exit();
	ft_check_name(params[0]);
	room->name = ft_strdup(params[0]);
	ft_check_digit(params[1]);
	ft_check_digit(params[2]);
	room->x = ft_atoi(params[1]);
	room->y = ft_atoi(params[2]);
}


t_room	*ft_find_end(char **str, int fd, t_room *room)
{
	ft_valid_room(*str, fd, room);
	room->next_room = (t_room *)malloc(sizeof(t_room));
	room = room->next_room;
	get_next_line(fd, str);
	return (room);

}

t_room	*ft_check_rooms(t_room *room, int fd, char **str)
{
	t_room 	*rooms;

	room = (t_room *)malloc(sizeof(t_room));
	rooms = room;
	get_next_line(fd, str);
	while (!ft_strstr(*str, "-"))
		room = ft_find_end(str, fd, room);
	room->next_room = NULL;
	return (rooms);
}

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

void	ft_check_num(t_lem *in, int fd)
{
	char	*str;

	get_next_line(fd, &str);
	while (str[0] == '#' && (ft_strcmp(str, "##start")) 
	&& (ft_strcmp(str, "##end")))
		get_next_line(fd, &str);
	in->num_ants = ft_atoi(str);
	ft_check_digit(str);
	if (!in->num_ants)
		ft_exit();
}

t_room			**ft_valid(t_lem *in, int fd)
{
	t_lem 	*lol;
	t_room	**mass_rooms;
	int		coun;
	char	*str;

	str = NULL;
	coun = 0;
	lol = in;
	ft_check_num(lol, fd);
	lol->room = ft_check_rooms(lol->room, fd, &str);
	mass_rooms = (t_room **)malloc(sizeof(t_room *) * ft_count_links(lol->room));
	while (in->room->next_room)
	{
		mass_rooms[coun] = in->room;
		in->room = in->room->next_room;
		coun++;
	}
	mass_rooms[coun] = NULL;
	coun = 0;
	while (mass_rooms[coun])
	{
		mass_rooms[coun]->r_name = NULL;
		mass_rooms[coun]->next_room = NULL;
		mass_rooms[coun]->right_way = 0;
		mass_rooms[coun]->free = 1;
		mass_rooms[coun]->ants = 0;
		mass_rooms[coun]->use = 0;
		mass_rooms[coun]->left_way = 0;
		mass_rooms[coun]->use_bk = 0;
		mass_rooms[coun]->length = 0;
		mass_rooms[coun]->length_cp = 0;
		mass_rooms[coun]->length_bk = 0;
		mass_rooms[coun]->length_bk_cp = 0;
		coun++;
	}
	ft_make_links(mass_rooms, fd, str);
	return (mass_rooms);
	// while (mass_rooms[coun])
	// {
	// 	ft_printf("%s ", mass_rooms[coun]->name);
	// 	ft_printf("x: %i ", mass_rooms[coun]->x);
	// 	ft_printf("y: %i ", mass_rooms[coun]->y);
	// 	ft_printf("start: %i ", mass_rooms[coun]->start);
	// 	ft_printf("fin: %i \n", mass_rooms[coun]->fin);
	// 	coun++;
	// }
}