/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:31:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/02 15:51:28 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// НАДО СДЕЛАТЬ НЕКСТ И ПРЕВ

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

// t_room	*ft_link(t_room *room, t_room **mass_rooms, char *name)
// {
// 	int	count;
// 	t_room *room_cp;
// 	t_room **mass_cp;

// 	room_cp = room;
// 	mass_cp = mass_rooms;
// 	count = 0;
// 	while (mass_rooms[count])
// 	{
// 		ft_printf("try find : %s ", mass_rooms[count]->name);
// 		if (!ft_strcmp(mass_rooms[count]->name, name))
// 		{
// 			// room->next = mass_rooms[count];
// 			// //room->next = NULL;
// 			// while (room_cp)
// 			// {
// 			// 	ft_printf("name b: %s ", room_cp->name);
// 			// 	room_cp = room_cp->next;
// 			// }
// 			return (mass_rooms[count]);
// 		}
// 		count++;
// 	}
// 	return (NULL);
// }

char	*ft_find_second(char *str)
{
	char	*ret;

	ret = ft_strchr(str, '-');
	ret++;
	return (ret);
}

t_name	*ft_make_first(int count, int name_r)
{
	t_name	*name;

	name = (t_name *)malloc(sizeof(t_name));
	name->name = name_r;
	name->num = count;
	name->next = NULL;
	return (name);
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

t_name		*ft_make_r_name(t_name *r_name, int count, int f_s)
{
	t_name *r_name_cp;

	r_name_cp = r_name;
	while (r_name->next)
	{
		if (count == 8)
			ft_printf("%i\n", r_name->num);
		ft_printf("check\n");
		r_name = r_name->next;
	}
	r_name->next = ft_make_first(f_s, 0);
	ft_printf("num : %i\n", r_name->num);
	return (r_name_cp);
}

void		ft_connect(t_room **mass_rooms_cp, t_links *links, int	count)
{
	int	f_s;

	t_room **mass_rooms;

	f_s = 0;
	mass_rooms = mass_rooms_cp;
	while (mass_rooms[count])
	{
		ft_printf("try find : %s \n", mass_rooms[count]->name);
		if (!ft_strcmp(mass_rooms[count]->name, links->f_name))
		{
			ft_printf("find : %s \n", links->f_name);
			if (!mass_rooms[count]->r_name)
				mass_rooms[count]->r_name = ft_make_first(count, 1);
			while (mass_rooms[f_s])
			{
				ft_printf("try find second: %s \n", mass_rooms[f_s]->name);
				if (!ft_strcmp(mass_rooms[f_s]->name, links->s_name))
				{
					ft_printf("find sec: %s \n", links->s_name);
					mass_rooms[count]->r_name = ft_make_r_name(mass_rooms[count]->r_name, count, f_s);
				}
				f_s++;
			}
		}
		f_s = 0;
		count++;
	}
}

void	ft_linked(t_links *links, char *str)
{
	char	*f_name;
	char	*s_name;

	f_name = ft_find_first(str);
	s_name = ft_find_second(str);
	links->use = 0;
	links->f_name = ft_strdup(f_name);
	links->s_name = ft_strdup(s_name);
}

void	ft_print_links(t_links	*links)
{
	while (links)
	{
		ft_printf("lin_nm %s\n", links->f_name);
		links = links->next;
	}
}

void	ft_try_recurs(t_room **mass_rooms, t_links *links)
{
	while (links)
	{
		ft_connect(mass_rooms, links, 0);
		links = links->next;
	}
}

void	ft_make_links(t_room **mass_rooms, int fd, char *str)
{
	int 	end;
	int		count;
	t_links	*links;
	t_links	*links_cp;
	t_room **mass_rooms_cp;
	int		num_rooms;

	num_rooms = 0;
	end = 1;
	count = 0;
	mass_rooms_cp = mass_rooms;
	links = (t_links *)malloc(sizeof(t_links));
	links_cp = links;
	while (end)
	{
		ft_check_valid_link(str);
		ft_linked(links, str);
		end = get_next_line(fd, &str);
		num_rooms++;
		if (end)
		{
			links->next = (t_links *)malloc(sizeof(t_links));
			links = links->next;
		}
	}
	links->next = NULL; 

	ft_try_recurs(mass_rooms_cp, links_cp);

	count = 0;
	while (mass_rooms[count])
	{
		if (mass_rooms[count]->r_name)
		{
			ft_printf("name : %s\n", mass_rooms[count]->name);
			while (mass_rooms[count]->r_name)
			{
				ft_printf("num->next : %i\n", mass_rooms[count]->r_name->num);
				ft_printf("name->next : %i\n", mass_rooms[count]->r_name->name);
				//ft_printf("len->next : %i\n", mass_rooms[count]->r_name->length);
				mass_rooms[count]->r_name = mass_rooms[count]->r_name->next;
			}
		}
		ft_printf("\n");
		count++;
	}
	// while (mass_rooms[2])
	// {
	// 	ft_printf("test\n");
	// 	ft_printf("room :%s ", mass_rooms[2]->name);
	// 	mass_rooms[2] = mass_rooms[2]->next;
	// }
	// while (get_next_line(fd, &str))
	// {
	// 	ft_printf("test");
	// 	ft_check_valid_link(str);
	// 	ft_connect(mass_rooms, str);
	// }
}
