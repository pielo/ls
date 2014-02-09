/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:59:24 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/09 19:03:29 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ls.h"
#include "libft.h"
#include <stdlib.h>

static char		*ft_add_spaces(char *nbr, int max)
{
	char		*tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = (char *)malloc(sizeof(nbr) * max);
	while (i < max)
	{
		tab[i] = ' ';
		i++;
	}
	while (nbr[j] != '\0')
		j++;
	while (j >=0)
	{
		tab[i] = nbr[j];
		i--;
		j--;
	}
	return (tab);
}

void			ft_max(f_list laliste, size_t *lmax, size_t *smax)
{
	f_list		*current;

	current = &laliste;
	while (current != NULL)
	{
		if (ft_strlen(current->link) > *lmax)
			*lmax = ft_strlen(current->link);
		if (ft_strlen(current->size) > *smax)
			*smax = ft_strlen(current->size);
		current = current->next;
	}
}

void			ft_aff_lst(f_list *laliste)
{
	size_t lmax;
	size_t smax;

	lmax = 1;
	smax = 1;
	ft_max(*laliste, &lmax, &smax);
	while (laliste != NULL)
	{
		ft_putchar(laliste->type);
		ft_putstr(laliste->mod);
		ft_putstr("  ");
		ft_putstr(ft_add_spaces(laliste->link, lmax));
		ft_putchar(' ');
		ft_putstr(laliste->user);
		ft_putstr("  ");
		ft_putstr(laliste->group);
		ft_putstr("  ");
		ft_putstr(ft_add_spaces(laliste->size, smax));
		ft_putchar(' ');
		ft_putstr(laliste->date);
		ft_putchar(' ');
		ft_putstr(laliste->name);
		ft_putchar('\n');
		laliste = laliste->next;
	}
}
