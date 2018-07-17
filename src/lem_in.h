/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:27 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:43:53 by dpogrebn         ###   ########.fr       */
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
	int				use_bk;
	int				last;
	int				num;
	struct s_name	*next;
}					t_name;

typedef	struct		s_links
{
	char			*f_name;
	char			*s_name;
	struct s_links	*next;
}					t_links;

typedef	struct		s_ants
{
	int				num;
	int				change;
	char			*name;
	struct s_ants	*next;
}					t_ants;

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				ways;
	int				left_way;
	int				free;
	int				use_bk;
	int				start;
	int				fin;
	int				length_bk;
	struct s_room	*next_room;
	struct s_name	*r_name;
}					t_room;

t_room				**ft_valid(int fd);
int					ft_check_num(int fd);
void				ft_make_links(t_room **mass_rooms, int fd, char *str);
void				ft_put_len(t_room **mass_rooms_cp);
void				ft_make_graph(t_room **mass_rooms, t_links *links);
void				ft_find_ways(t_room **mass_rooms);
void				ft_finish_way(t_room **mass_rooms, int start,
int fin, int count_ways);
int					ft_find_len_bk(t_room **mass_rooms);
void				ft_print_room(t_room **mass_rooms);
int					ft_find_start(t_room **mass_rooms);
int					ft_find_finish(t_room **mass_rooms);
void				ft_move_ants(int ants, t_room **mass_rooms);
void				ft_comment(char **str, int fd, t_room *room);
void				ft_make_way(t_room **mass_rooms);
void				ft_free_links(t_links *links);
void				ft_check_valid_link(char *str);
char				*ft_find_first(char *str);
char				*ft_find_second(char *str);
int					ft_find_cont(char *name, t_room **mass_rooms);
void				ft_check_right_name(char *f, t_room **mass_rooms);
void				ft_free_links(t_links *links);
void				ft_check_digit(char *str);
void				ft_check_rights(t_room **mass_rooms);
t_ants				*ft_print_ants(t_ants *ants_cp, char *finish);
t_room				*ft_check_rooms(t_room *room, int fd, char **str);
int					ft_find_next(t_name *room,
t_room **mass_rooms, int count);
t_ants				*ft_start(t_room **mass_rooms, int count,
int in, t_ants *ant);
void				ft_exit();

#endif
