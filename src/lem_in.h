/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:27 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/31 19:44:30 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef	struct		s_name
{
	char			*name;
	int				length;
	int				num;
	struct s_name	*next;
	struct s_name	*prev;
}					t_name;

typedef	struct		s_links
{
	char			*f_name;
	char			*s_name;
	int				use;
	struct s_links	*next;
}					t_links;

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				free;
	int				start;
	int				fin;
	int				length;
	struct s_room	*next_room;
	struct s_name	*name;
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
void	ft_exit();

#endif
