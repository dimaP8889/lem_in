/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:27 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/21 18:49:21 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				free;
	int				start;
	int				fin;
	struct s_room	*next;
}					t_room;

typedef	struct		s_lem
{
	int				num_ants;
	t_room			*room;
}					t_lem;

void	ft_valid(t_lem *in, int fd);

#endif
