#include "libft/libft.h"
#include "libft_ls.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	f_list	flist;
	int		i;

	i = 1;
	if (argc == 1)
	{
		flist = ft_list_dir(".");
		ft_aff_lst(&flist);
	}
	else
	{
		while (i < argc)
		{
			printf("%s ", argv[i]);
			flist = ft_list_dir(argv[i]);
			ft_aff_lst(&flist);
			i++;
		}
		printf("\n");
	}
	return (0);
}
