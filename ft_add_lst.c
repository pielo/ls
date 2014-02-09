/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:23:23 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/09 19:03:45 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "libft_ls.h"

void	ft_add_lst(f_list **alst, f_list *new)
{
	f_list		*prec;
	f_list		*suiv;

	prec = NULL;
	suiv = *alst;
	while (suiv && ft_strcmp(suiv->name, new->name) < 0)
	{
		prec = suiv;
		suiv = suiv->next;
	}
	if (!suiv)
		prec->next = new;
	else
	{
		if (prec)
		{
			new->next = prec->next;
			prec->next = new;
		}
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}

