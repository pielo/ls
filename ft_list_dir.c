/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:31:26 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/09 19:01:45 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_ls.h"
#include <dirent.h>
#include <stdlib.h>

f_list		ft_list_dir(char *dir)
{
	DIR				*dirp;
	struct dirent	*fic;
	f_list			*truc;

	dirp = opendir(dir);
	fic = readdir(dirp);
	truc = ft_remp_one(fic->d_name);
	while ((fic = readdir(dirp)) != NULL)
	{
		ft_add_lst(&truc, ft_remp_one(fic->d_name));
	}
	closedir(dirp);
	return (*truc);
}
