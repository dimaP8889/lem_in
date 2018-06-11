/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:19:33 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/06/11 01:16:48 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_free(t_name *room, t_room **mass_rooms, int len)
{
	while (room)
	{
		if ((mass_rooms[room->num]->left_way || mass_rooms[room->num]->right_way) 
		&& mass_rooms[room->num]->free && !mass_rooms[room->num]->start 
		&& mass_rooms[room->num]->length > len)
			return (room->num);
		room = room->next;
	}
	return (-1);
}

void	ft_change_room(t_ants *ants, char *dst, char *src)
{
	// ft_printf("src :%s\n", src);
	// ft_printf("dst :%s\n", dst);
	while (ants)
	{
		//ft_printf("name %s\n", ants->name);
		if (!ft_strcmp(ants->name, src))
		{
			ants->name = dst;
			//ft_printf("name_dst %s\n", ants->name);
			//ft_printf("name_src %s\n", src);
			return;
		}
		ants = ants->next;
	}
	//ft_printf("\n");
}

void	ft_check_near(t_room **mass_rooms, int num, t_ants *ants_cp)
{
	int		count;
	int		next_num;
	t_ants	*ants;

	ants = ants_cp;
	count = 0;
	while (mass_rooms[count])
	{
		if (mass_rooms[count]->length == num)
		{
			if (!mass_rooms[count]->free)
			{
				next_num = ft_find_free(mass_rooms[count]->r_name, mass_rooms, num);
				if (next_num != -1)
				{
					//ft_printf("num : %i\n", count);
					//ft_printf("next_num : %i\n", next_num);
					mass_rooms[next_num]->free = 0;
					ft_change_room(ants, mass_rooms[next_num]->name, mass_rooms[count]->name);
					if (mass_rooms[next_num]->fin)
					{
						mass_rooms[next_num]->ants++;
						mass_rooms[next_num]->free = 1;
					}
					mass_rooms[count]->free = 1;
				}
			}
		}
		count++;
	}
}

t_ants 	*ft_make_next_ant(char *name, int num, t_ants *ant)
{
	t_ants *ant_cp;

	ant_cp = ant;
	while (ant->next)
		ant = ant->next;
	ant->next = (t_ants *)malloc(sizeof(t_ants));
	ant->next->name = name;
	ant->next->num = num;
	ant->next->next = NULL;
	return (ant_cp);
}

t_ants 	*ft_make_ant(char *name, int num)
{
	t_ants *ant;

	ant = (t_ants *)malloc(sizeof(t_ants));
	ant->name = name;
	ant->num = num;
	ant->change = 0;
	ant->next = NULL;
	return (ant);
}

t_ants 	*ft_start(t_name *room, t_room **mass_rooms, int start, t_ants *ants)
{
	static	int	ant;

	//ant_cp = ants;
	if (!ant)
		ant = 1;
	//ft_printf("%i\n", mass_rooms[start]->ants);
	while (room && mass_rooms[start]->ants)
	{
		//ft_printf("test\n");
		if ((mass_rooms[room->num]->left_way || mass_rooms[room->num]->right_way) 
		&& mass_rooms[room->num]->free)
		{
			//ft_printf("test\n");
			if (!ants)
			{
				//ft_printf("test\n");
				ants = ft_make_ant(mass_rooms[room->num]->name, ant);
			}
			else
			{
				//ft_printf("num_ant :%i\n", ant);
				ants = ft_make_next_ant(mass_rooms[room->num]->name, ant, ants);
				//ft_printf("num_ant :%i\n", ants->num);
			}
			mass_rooms[start]->ants--;
			mass_rooms[room->num]->free = 0;
			ant++;
		}
		room = room->next;
	}
	return (ants);
}

void	ft_print_ants(t_ants *ants) // make right OUT
{
	while (ants)
	{
		ft_printf("L%i-", ants->num);
		ft_printf("%s ", ants->name);
		ants = ants->next;
	}
	ft_printf("\n");
}
t_ants 	*ft_one_move(t_room **mass_rooms, int start, int moves, t_ants *ants)
{
	//ft_printf("moves %i\n", moves);
	while (moves)
	{
		ft_check_near(mass_rooms, moves, ants);
		moves--;
	}
	if (!moves)
	{
		ants = ft_start(mass_rooms[start]->r_name, mass_rooms, start, ants);
		//ft_print_ants(ants);
	}
	return (ants);
}	


void	ft_move_ants(int num_ants, t_room **mass_rooms)
{
	int		finish;
	int		start;
	int		moves;
	t_ants	*ants;

	moves = 0;
	ants = NULL;
	finish = ft_find_finish(mass_rooms);
	start = ft_find_start(mass_rooms);
	mass_rooms[start]->ants = num_ants;
	while (mass_rooms[finish]->ants < num_ants)
	{
		//ft_printf("move :%i\n", moves);
		if (moves > mass_rooms[finish]->length)
			moves = mass_rooms[finish]->length;
		ants = ft_one_move(mass_rooms, start, moves, ants);
		ft_print_ants(ants);
		moves++;
		//mass_rooms[finish]->ants++;
	}
}