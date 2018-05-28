/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:31:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/28 13:21:25 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_valid_link(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '-')
	{
		if (!ft_isdigit(str[i]))
			ft_exit();
		i++;
	}
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
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

t_room	*ft_link(t_room **mass_rooms, char *name)
{
	int	count;

	count = 0;
	while (mass_rooms[count])
	{
		if (ft_strcmp(mass_rooms[count]->name, name))
			return (mass_rooms[count]);
		count++;
	}
	return (NULL);
}

char	*ft_find_second(char *str)
{
	char	*ret;

	ret = ft_strchr(str, '-');
	ret++;
	return (ret);
}

void	ft_connect(t_room **mass_rooms, char *str)
{
	int		count;
	char	*f_name;
	char	*s_name;
	t_room	**cp_rooms;

	count = 0;
	cp_rooms = mass_rooms;
	f_name = ft_find_first(str);
	s_name = ft_find_second(str);
	ft_printf("%s\n", f_name);
	ft_printf("%s\n", s_name);
	while (mass_rooms[count])
	{
		if (ft_strcmp(mass_rooms[count]->name, f_name))
		{
			while (mass_rooms[count]->next)
			{
				mass_rooms[count] = mass_rooms[count]->next;
			}
			mass_rooms[count]->next = (t_room *)malloc(sizeof(t_room));
			//mass_rooms[count] = mass_rooms[count]->next;
			mass_rooms[count]->next = ft_link(cp_rooms, s_name);
			mass_rooms[count]->next->next = NULL;
			//mass_rooms[count]->next = NULL;
		}
		count++;
	}
}

void	ft_make_links(t_room **mass_rooms, int fd, char *str)
{
	int end;

	end = 1;
	while (end)
	{
		ft_check_valid_link(str);
		ft_connect(mass_rooms, str);
		end = get_next_line(fd, &str);
	}

	// while (get_next_line(fd, &str))
	// {
	// 	ft_printf("test");
	// 	ft_check_valid_link(str);
	// 	ft_connect(mass_rooms, str);
	// }
}
