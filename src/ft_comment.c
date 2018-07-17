/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:40:37 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:59:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int		ft_if_start(char **str, int start, int fd, t_room *room)
{
	if (!ft_strcmp(*str, "##start"))
	{
		start++;
		(room)->start = 1;
		free(*str);
		get_next_line(fd, str);
		ft_printf("%s\n", *str);
		if (*str[0] == '#')
			ft_comment(str, fd, room);
	}
	else if (!room->start)
		(room)->start = 0;
	return (start);
}

int		ft_if_end(char **str, int fin, int fd, t_room *room)
{
	if (!ft_strcmp(*str, "##end"))
	{
		fin++;
		free(*str);
		(room)->fin = 1;
		get_next_line(fd, str);
		ft_printf("%s\n", *str);
		if (*str[0] == '#')
			ft_comment(str, fd, room);
	}
	else if (!room->fin)
		(room)->fin = 0;
	return (fin);
}

void	ft_comment(char **str, int fd, t_room *room)
{
	static int	start;
	static int	fin;

	while (*str[0] == '#' && (ft_strcmp(*str, "##start"))
	&& (ft_strcmp(*str, "##end")))
	{
		free(*str);
		get_next_line(fd, str);
		ft_printf("%s\n", *str);
	}
	start = ft_if_start(str, start, fd, room);
	fin = ft_if_end(str, fin, fd, room);
	if (start > 1 || fin > 1)
	{
		ft_exit();
	}
	*str[0] == '#' ? ft_comment(str, fd, (room)) : *str[0] == '#';
}
