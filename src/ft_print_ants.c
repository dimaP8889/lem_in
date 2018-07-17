/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:16:54 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/15 14:18:17 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants		*ft_print_ants(t_ants *ants_cp, char *finish)
{
	t_ants	*ants;

	ants = ants_cp;
	if (ants && !ft_strcmp(ants->name, finish))
	{
		//ft_printf("L%i-", ants->num);
		//ft_printf("%s ", ants->name);
		free(ants_cp);
		ants_cp = ants_cp->next;
		ants = ants->next;
	}
	while (ants)
	{
		//ft_printf("L%i-", ants->num);
		//ft_printf("%s ", ants->name);
		ants = ants->next;
	}
	//ft_printf("\n");
	return (ants_cp);
}
