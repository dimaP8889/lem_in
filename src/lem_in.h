/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:27 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/06 12:22:27 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef	struct		s_name
{
	int				use;
	int				num;
	struct s_name	*next;
}					t_name;

typedef	struct		s_links
{
	char			*f_name;
	char			*s_name;
	struct s_links	*next;
}					t_links;

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				right_way;
	int				free;
	int				start;
	int				fin;
	int				length;
	struct s_room	*next_room;
	struct s_name	*r_name;
}					t_room;

typedef	struct		s_lem
{
	int				num_ants;
	int				start;
	int				fin;
	t_room			*room;
}					t_lem;

void	ft_valid(t_lem *in, int fd);
void	ft_make_links(t_room **mass_rooms, int fd, char *str);
void	ft_put_len(t_room **mass_rooms_cp);
void	ft_make_graph(t_room **mass_rooms, t_links *links);
void	ft_find_ways(t_room **mass_rooms);
void	ft_exit();

#endif
