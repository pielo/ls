/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:32:09 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/09 19:04:00 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_ls.h"
#include "libft.h"
#include <unistd.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

static char		ft_type(struct stat buf)
{
	char		c;
	if (S_ISREG(buf.st_mode))
		c = '-';
	if (S_ISDIR(buf.st_mode))
		c = 'd';
	if (S_ISCHR(buf.st_mode))
		c = 'c';
	if (S_ISBLK(buf.st_mode))
		c = 'b';
	if (S_ISFIFO(buf.st_mode))
		c = 'p';
	if (S_ISLNK(buf.st_mode))
		c = 'l';
	if (S_ISSOCK(buf.st_mode))
		c = 's';
	return (c);
}

static char		*ft_mod(struct stat buf)
{
	char		*mod;

	mod = ft_strnew(10);
	ft_strcpy(mod, "---------");
	if (buf.st_mode & S_IRUSR)
		mod[0] = 'r';
	if (buf.st_mode & S_IWUSR)
		mod[1] = 'w';
	if (buf.st_mode & S_IXUSR)
		mod[2] = 'x';
	if (buf.st_mode & S_IRGRP)
		mod[3] = 'r';
	if (buf.st_mode & S_IWGRP)
		mod[4] = 'w';
	if (buf.st_mode & S_IXGRP)
		mod[5] = 'x';
	if (buf.st_mode & S_IROTH)
		mod[6] = 'r';
	if (buf.st_mode & S_IWOTH)
		mod[7] = 'w';
	if (buf.st_mode & S_IXOTH)
		mod[8] = 'x';
	return (mod);
}

f_list			*ft_remp_one(char *file)
{
	struct stat		buf;
	struct passwd	*user;
	struct group	*group;
	f_list			*list;

	list = (f_list *)malloc(sizeof(*list));
	stat(file, &buf);
	user = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	list->type = ft_type(buf);
	list->mod = (char *)malloc(sizeof(char) * 10);
	ft_memcpy(list->mod, ft_mod(buf), 10);
	list->link = ft_itoa(buf.st_nlink);
	list->user = (char *)malloc(sizeof(char) * ft_strlen(user->pw_name));
	ft_memcpy(list->user, user->pw_name, ft_strlen(user->pw_name));
	list->group = (char *)malloc(sizeof(char) * ft_strlen(group->gr_name));
	ft_memcpy(list->group, group->gr_name, ft_strlen(group->gr_name));
	list->size = ft_itoa(buf.st_size);
	list->date = (char *)malloc(sizeof(char) * 13);
	ft_memcpy(list->date, ft_strsub(ctime(&buf.st_mtime), 4, 12), 12);
	list->date[12] = '\0';
	list->name = (char *)malloc(sizeof(char) * ft_strlen(file)); 
	ft_memcpy(list->name, file, strlen(file));
	list->next = (f_list *)malloc(sizeof(*list));
	list->next = NULL;
	return (list);
}
