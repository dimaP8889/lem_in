/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:31:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/15 13:39:15 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_linked(t_links *links, char *str, t_room **mass_rooms)
{
	char	*f_name;
	char	*s_name;

	f_name = ft_find_first(str);
	s_name = ft_find_second(str);
	links->f_name = ft_strdup(f_name);
	links->s_name = ft_strdup(s_name);
	ft_check_right_name(links->f_name, mass_rooms);
	ft_check_right_name(links->s_name, mass_rooms);
	free(f_name);
}

void		ft_malloc_link(int end, t_links **links)
{
	if (end)
	{
		(*links)->next = (t_links *)malloc(sizeof(t_links));
		*links = (*links)->next;
		(*links)->next = NULL;
	}
}

int			ft_lose(char **str, int fd)
{
	int		end;

	end = 0;
	while (*str[0] == '#')
	{
		free(*str);
		end = get_next_line(fd, str);
		ft_printf("%s\n", str);
	}
	return (end);
}

t_links		*ft_check_links(t_room **mass_rooms, int fd, char *str)
{
	int		end;
	t_links	*links;
	t_links	*links_cp;

	links = (t_links *)malloc(sizeof(t_links));
	links->next = NULL;
	links_cp = links;
	end = 1;
	while (end)
	{
		if (str[0] == '#')
			end = ft_lose(&str, fd);
		if (!end)
			break ;
		ft_check_valid_link(str);
		ft_linked(links, str, mass_rooms);
		free(str);
		end = get_next_line(fd, &str);
		ft_printf("%s\n", str);
		if (str[0] == '#')
			end = ft_lose(&str, fd);
		ft_malloc_link(end, &links);
	}
	links->next = NULL;
	return (links_cp);
}

void		ft_make_links(t_room **mass_rooms, int fd, char *str)
{
	t_links	*links;

	links = ft_check_links(mass_rooms, fd, str);
	ft_make_graph(mass_rooms, links);
	ft_free_links(links);
	ft_put_len(mass_rooms);
	ft_make_way(mass_rooms);
}
