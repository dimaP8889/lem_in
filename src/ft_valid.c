/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/23 20:18:59 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_comment(char **str, int fd, t_room *room)
{
	while (*str[0] == '#' && (ft_strcmp(*str, "##start")) 
	&& (ft_strcmp(*str, "##end")))
		get_next_line(fd, str);
	if (!ft_strcmp(*str, "##start"))
	{
		room->start = 1;
		get_next_line(fd, str);
	}
	if (!ft_strcmp(*str, "##end"))
		return (0);
	return (1);
}

int	ft_command(char *str, int fd, t_room *room)
{
	while (str[0] == '#' && str[1] == '#')
	{
		if (!ft_strcmp(str, "##start"))
		{
			room->start = 1;
			get_next_line(fd, &str);
		}
		if (!ft_strcmp(str, "##end"))
			return (0);
		get_next_line(fd, &str);
	}
	return (1);
}

int		ft_mass_len(char **mass)
{
	int		len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

void	ft_exit()
{
	ft_printf("ERROR\n");
	exit(1);
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

int		ft_valid_room(char *str, int fd, t_room *room)
{
	char	**params;
	static int	start;
	static int	fin;

	if (!ft_strcmp(str, "##start"))
		start++;
	if (!ft_strcmp(str, "##end"))
		fin++;
	if (start > 1|| fin > 1)
		ft_exit();
	if (!ft_strcmp(str, "##start"))
	{
		room->start = 1;
		get_next_line(fd, &str);
	}
	else
		room->start = 0;
	if (str[0] == '#')
		ft_comment(&str, fd, room);
	params = ft_strsplit(str, ' ');
	if (ft_mass_len(params) != 3 || !ft_strlen(str))
	{
		ft_exit();
	}
	room->name = ft_strdup(params[0]);
	ft_check_digit(params[1]);
	ft_check_digit(params[2]);
	room->x = ft_atoi(params[1]);
	room->y = ft_atoi(params[2]);
	room->fin = 0;
	return (1);
}

t_room	*ft_check_rooms(t_room *room, int fd)
{
	char	*str;
	t_room 	*rooms;
	// static int	start;
	// static int	fin;

	room = (t_room *)malloc(sizeof(t_room));
	rooms = room;
	get_next_line(fd, &str);
	while (ft_strcmp(str, "##end"))
	{
		if (!ft_valid_room(str, fd, room))
			break;
		room->next = (t_room *)malloc(sizeof(t_room));
		room = room->next;
		get_next_line(fd, &str);
	}
	get_next_line(fd, &str);
	ft_valid_room(str, fd, room);
	room->fin = 1;
	while (!ft_strstr(str, "-"))
	{
		if (!ft_valid_room(str, fd, room))
			break;
		room->next = (t_room *)malloc(sizeof(t_room));
		room = room->next;
		get_next_line(fd, &str);
	}
	room->next = NULL;
	return (rooms);
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

void	ft_valid(t_lem *in, int fd)
{
	t_lem *lol;

	lol = in;
	ft_check_num(lol, fd);
	lol->room = ft_check_rooms(lol->room, fd);
	while (in->room)
	{
		ft_printf("%s\n", in->room->name);
		in->room = in->room->next;
	}
}