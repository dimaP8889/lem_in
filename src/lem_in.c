/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:02:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/23 18:20:26 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_lem	*in;
	int		fd;

	in = (t_lem *)malloc(sizeof(t_lem));
	fd = open("src/read", O_RDONLY);
	ft_valid(in, fd);
}