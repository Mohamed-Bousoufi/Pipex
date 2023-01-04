/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:27:10 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/04 11:27:47 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	o_file(char *f, int op)
{
	int	ret;

	ret = 0;
	if (op == 1)
		ret = open(f, O_RDONLY, 0777);
	if (op == 2)
		ret = open(f, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
	{
		perror("I/O File_Not_Found");
		exit(errno);
	}
	return (ret);
}

char	*ft_malloc(int size)
{
	char	*s;

	s = malloc(size);
	if (!s)
	{
		free(s);
		perror(" !!!allocation ");
		exit(errno);
	}
	return (s);
}

void	frepath(char **cmd)
{
	int	j;

	j = 0;
	while (cmd[j])
	{
		free(cmd[j]);
		j++;
	}
	free(cmd);
	cmd = NULL;
}

char	*f_slach(char *ar)
{
	char	**tab;
	char	*str;

	tab = ft_split(ar, ' ');
	str = ft_strjoin("/", tab[0]);
	frepath(tab);
	return (str);
}
