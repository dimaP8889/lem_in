/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:31:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/31 20:12:34 by dmitriy1         ###   ########.fr       */
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

// void	ft_connect(t_room **mass_rooms, char *str)
// {
// 	int		count;
// 	char	*f_name;
// 	char	*s_name;
// 	t_room	**cp_rooms;

// 	count = 0;
// 	cp_rooms = mass_rooms;
// 	f_name = ft_find_first(str);
// 	s_name = ft_find_second(str);
// 	//mass_rooms[1]->name = "LOL";
// 	while (mass_rooms[count])
// 	{
// 		ft_printf("name : %s ", mass_rooms[count]->name);
// 		if (!ft_strcmp(mass_rooms[count]->name, f_name))
// 		{
// 			while (mass_rooms[count]->next)
// 				mass_rooms[count] = mass_rooms[count]->next;
// 			mass_rooms[count]->next = ft_link(mass_rooms[count], mass_rooms, s_name);
// 			ft_printf("link : %s\n", mass_rooms[count]->name);
// 			//cp_rooms[count]->next->next = NULL;
// 			break ;
// 		}
// 		count++;
// 	}
// }

t_name	*ft_make_room(int length, int num)
{
	t_name	*room;

	room = (t_name *)malloc(sizeof(t_name));
	room->num = num;
	ft_printf("num_prev: %i\n", num);
	//if (length < room->length)
		room->length = length;
	return (room);
}

t_name	*ft_make_prev(int length, int num)
{
	t_name	*room;

	room = (t_name *)malloc(sizeof(t_name));
	room->num = num;
	ft_printf("num_prev: %i\n", num);
	//if (length < room->length)
		room->length = length;
	return (room);
}

t_name	*ft_make_next(int length, char *name, t_room **mass_rooms)
{
	int		num;
	t_name	*room;

	room = (t_name *)malloc(sizeof(t_name));	
	num = 0;
	while (ft_strcmp(mass_rooms[num]->name, name))
		num++;
	room->num = num;
	ft_printf("len: %i\n", length);
	//if (length < room->length)
		room->length = length;
	return (room);
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

int		ft_set_length(t_name *rooms, t_links *links, int length, int num)
{
	int		ret;
	t_name	*rooms_cp;

	ret = 0;
	if (!rooms)
	{
		rooms = ft_make_room();
		rooms->prev = NULL;
		rooms->next = NULL;
	}
	while (links)
	{
		if (!links->use)
			ret++;
		if (!ft_strcmp(rooms->name, links->f_name) && !links->use)
			break;
		ft_printf("mass_name :%s find_name : %s\n", rooms->name, links->f_name);
		links = links->next;
	}
	if (!links && ret > 0)
		return (2);
	else if (!ret && !links)
		return (0);
	links->use = 1;
	if (!) // НАДО СДЕЛАТЬ НЕКСТ И ПРЕВ
	rooms->next = ft_make_next(length, links->s_name, mass_rooms);
	return (1);

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
	int		length;
	int		count;
	int		save;
	int		found;
	t_links	*links_cp;

	length = 1;
	links_cp = links;
	count = 0;
	found = 1;
	while (!mass_rooms[count]->fin)
		count++;
	mass_rooms[count]->length = 0;
	save = count;
	int i = 0;
	ft_print_links(links_cp);
	while (i < 10)
	{
		//ft_printf("count_name : %s\n", mass_rooms[count]->name);
		found = ft_set_length(mass_rooms[num]->name, links_cp, length, count);

		if (!found)
		{
			break;
		}
		if (found == 2)
		{
			count = mass_rooms[count]->prev->num;
			length--;
			ft_printf("ct: %i\n", count);
		}
		else
		{
			save = count;
			count = mass_rooms[count]->next->num;
			//ft_printf("sv: %i\n", save);
		}
		ft_printf("count: %i\n", count);
		length++;
		i++;
	}


}

void	ft_make_links(t_room **mass_rooms, int fd, char *str)
{
	int 	end;
	int		count;
	t_links	*links;
	int		length;
	int		found;
	t_links	*links_cp;

	length = 1;
	found = 1;
	end = 1;
	count = 0;
	links = (t_links *)malloc(sizeof(t_links));
	links_cp = links;
	while (end)
	{
		ft_check_valid_link(str);
		ft_linked(links, str);
		end = get_next_line(fd, &str);
		if (end)
		{
			links->next = (t_links *)malloc(sizeof(t_links));
			links = links->next;
		}
	}
	links->next = NULL; 

	ft_try_recurs(mass_rooms, links_cp);
	count = 0;
	while (mass_rooms[count])
	{
		if (mass_rooms[count]->room)
		{
			ft_printf("num %i\n", count);
			ft_printf("num->next : %i\n", mass_rooms[count]->next->num);
			ft_printf("len->next : %i\n", mass_rooms[count]->next->length);
		}
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
