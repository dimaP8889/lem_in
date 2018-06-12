/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 01:34:06 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/12 19:38:52 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_len_bk(t_room **mass_rooms)
{
	int		count;
	int		len;

	len = 0;
	count = 0;
	while (mass_rooms[count])
	{
		if (mass_rooms[count]->length_bk_cp > len)
			len = mass_rooms[count]->length_bk_cp;
		count++;
	}
	return (len);
}
