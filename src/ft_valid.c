/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:40 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/15 18:07:39 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_comment(char *str, int fd)
{
	if (!ft_strlen(str))
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	while (str[0] == '#' && str[1] != '#')
		get_next_line(fd, str);
}

void	ft_check_num(t_lem in, int fd)
{
	char	*str;

	get_next_line(fd, str);
	ft_comment(str, fd);
	if (!ft_atoi(str))
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}

void	ft_valid(t_lem in, int fd)
{
	ft_check_num(in, fd);
}