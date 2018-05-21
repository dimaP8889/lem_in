/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/21 19:02:58 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_comment(char *str, int fd)
{
	while (str[0] == '#' && str[1] != '#')
		get_next_line(fd, &str);
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

void	ft_valid_room(char *str, int fd, t_room *room)
{
	char	**params;

	if (!ft_strcmp(str, "##start"))
	{
		room->start = 1;
		get_next_line(fd, &str);
	}
	else
		room->start = 0;
	params = ft_strsplit(str, ' ');
	if (ft_mass_len(params) != 3)
		ft_exit();
	room->name = ft_strdup(params[0]);
	ft_check_digit(params[1]);
	ft_check_digit(params[2]);
	room->x = ft_atoi(params[1]);
	room->y = ft_atoi(params[2]);
	room->fin = 0;
}

void	ft_check_rooms(t_lem *in, int fd)
{
	char	*str;

	get_next_line(fd, &str);
	in->room = (t_room *)malloc(sizeof(t_room));
	while (ft_strcmp(str, "##end"))
	{
		ft_printf("%s\n", str);
		ft_valid_room(str, fd, in->room);
		in->room->next = (t_room *)malloc(sizeof(t_room));
		in->room = in->room->next;
		get_next_line(fd, &str);
	}
	get_next_line(fd, &str);
	ft_printf("%s\n", str);
	ft_valid_room(str, fd, in->room);
	in->room->fin = 1;
	in->room->next = NULL;
}

void	ft_check_num(t_lem *in, int fd)
{
	char	*str;

	get_next_line(fd, &str);
	//ft_comment(str, fd);
	in->num_ants = ft_atoi(str);
	if (!in->num_ants)
		ft_exit();
}

void	ft_valid(t_lem *in, int fd)
{
	ft_check_num(in, fd);
	ft_check_rooms(in, fd);
}