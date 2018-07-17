/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 01:34:06 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/15 14:45:05 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_digit(char *str)
{
	int	num;

	num = 0;
	while (str[num])
	{
		if (!ft_isdigit(str[num]))
		{
			ft_exit();
		}
		num++;
	}
}

void	ft_free_links(t_links *links)
{
	t_links	*links_cp;

	while (links)
	{
		free(links->f_name);
		free(links->s_name);
		links_cp = links;
		links = links->next;
		free(links_cp);
	}
}
