/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:15:28 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/09 19:02:33 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include "libft.h"

#ifndef LIBFT_LS_H
# define LIBFT_LS_H

typedef struct		slist
{
	char			type;
	char			*mod;
	char			*link;
	char			*user;
	char			*group;
	char			*size;
	char			*date;
	char			*name;
	struct slist	*next;
}					f_list;

f_list	ft_list_dir(char *dir);
f_list	*ft_tri_ascii(f_list *lst);
void	ft_aff_lst(f_list *laliste);
void	ft_add_lst(f_list **alst, f_list *new);
f_list	*ft_remp_one(char *file);

#endif
