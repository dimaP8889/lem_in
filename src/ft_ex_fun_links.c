/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_fun_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:54:19 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 13:34:36 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_valid_link(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '-')
	{
		i++;
		if (!str[i])
			ft_exit();
	}
	i++;
	while (str[i])
	{
		if (str[i] == '-')
			ft_exit();
		i++;
	}
}

char	*ft_find_first(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '-')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '-')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_find_second(char *str)
{
	char	*ret;

	ret = ft_strchr(str, '-');
	ret++;
	return (ret);
}

int		ft_find_cont(char *name, t_room **mass_rooms)
{
	int	count;

	count = 0;
	while (ft_strcmp(name, mass_rooms[count]->name))
	{
		if (!mass_rooms[count])
			ft_exit();
		count++;
	}
	return (count);
}

void	ft_check_right_name(char *f, t_room **mass_rooms)
{
	int		count;

	count = 0;
	while (mass_rooms[count])
	{
		if (!ft_strcmp(mass_rooms[count]->name, f))
			return ;
		count++;
	}
	ft_exit();
}
