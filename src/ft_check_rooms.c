/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:31:10 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:44:41 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_name(char *str)
{
	if (str[0] == 'L' || ft_strstr(str, "-"))
	{
		ft_exit();
	}
}

int		ft_mass_len(char **mass)
{
	int		len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

void	ft_valid_room(char **str, int fd, t_room *room)
{
	char	**params;
	int		count;

	count = 0;
	room->fin = 0;
	room->start = 0;
	if (*str[0] == '#')
		ft_comment(str, fd, room);
	if (ft_strstr(*str, "-"))
		return ;
	params = ft_strsplit(*str, ' ');
	if (ft_mass_len(params) != 3 || !ft_strlen(*str))
		ft_exit();
	ft_check_name(params[0]);
	room->name = ft_strdup(params[0]);
	ft_check_digit(params[1]);
	ft_check_digit(params[2]);
	room->x = ft_atoi(params[1]);
	room->y = ft_atoi(params[2]);
	while (params[count])
	{
		free(params[count]);
		count++;
	}
	free(params);
}

t_room	*ft_find_end(char **str, int fd, t_room *room)
{
	ft_valid_room(str, fd, room);
	if (ft_strstr(*str, "-") && *str[0] != '#')
		return (room);
	free(*str);
	room->next_room = (t_room *)malloc(sizeof(t_room));
	room = room->next_room;
	get_next_line(fd, str);
	ft_printf("%s\n", *str);
	return (room);
}

t_room	*ft_check_rooms(t_room *room, int fd, char **str)
{
	t_room	*rooms;

	room = (t_room *)malloc(sizeof(t_room));
	rooms = room;
	get_next_line(fd, str);
	ft_printf("%s\n", *str);
	while (!ft_strstr(*str, "-") || (ft_strstr(*str, "-") && *str[0] == '#'))
	{
		room = ft_find_end(str, fd, room);
	}
	room->next_room = NULL;
	return (rooms);
}
