/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:43:41 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/14 18:19:18 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		countlet(char const *s, char c)
{
	int index;

	index = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		index++;
		s++;
	}
	return (index + 1);
}

static int		count(char const *s, char c)
{
	int index;

	index = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (index + 1);
		while (*s != c && *s)
			s++;
		if (*s == '\0')
		{
			index++;
			return (index + 1);
		}
		index++;
	}
	return (index + 1);
}

static	char	*make_word(char const *s, int *i, char c)
{
	char	*str;
	char	*str1;
	int		b;
	int		count;

	count = countlet(s, c);
	b = *i;
	while (*s == c)
	{
		s++;
		b++;
	}
	str = (char *)malloc(sizeof(char) * (count));
	if (str == NULL)
		return (NULL);
	str1 = str;
	while (count - 1 > 0)
	{
		*(str++) = *(s++);
		b++;
		count--;
	}
	*str = '\0';
	*i = b;
	return (str1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	**split1;
	char	*str;
	int		i;
	int		coun;

	if (!s)
		return (NULL);
	coun = count(s, c);
	split = (char **)malloc(sizeof(char *) * (coun));
	if (split == NULL)
		return (NULL);
	split1 = split;
	while (--coun > 0)
	{
		i = 0;
		str = make_word(s, &i, c);
		*split = ft_strdup(str);
		free(str);
		split++;
		s = s + i;
	}
	*split = 0;
	return (split1);
}
