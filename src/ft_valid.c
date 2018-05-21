/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/21 11:34:54 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_comment(char *str, int fd)
{
	while (str[0] == '#' && str[1] != '#')
		get_next_line(fd, str);
}

void	ft_valid_room(char *str, int fd, t_room room)
{

}

void	ft_command(char *str, int fd)
{
	while (str[0] == '#' && str[1] == '#')
	{
		if(!ft_strcmp(str, "##start"))
		{
			
		}
		if(!ft_strcmp(str, "##end"))
		get_next_line(fd, str);
	}
}

void	ft_check_rooms(t_lem in, int fd)
{
	while (!ft_strcmp(str, "##end"))
	{
		get_next_line(fd, str);
		if(!ft_strcmp(str, "##start"))

	}
}

void	ft_check_num(t_lem in, int fd)
{
	char	*str;

	get_next_line(fd, str);
	ft_comment(str, fd);
	in->num_ants = ft_atoi(str);
	if (!in->num_ants)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}

void	ft_valid(t_lem in, int fd)
{
	ft_check_num(in, fd);
	ft_check_rooms(in, fd);
}