/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:41:38 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 12:27:26 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_select(char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (!strncmp(path[i], "PATH", 4))
		{
			return (path[i]);
		}
		i++;
	}
	return (NULL);
}

char	*pathcmd(char *str, char **env)
{
	int		i;
	char	**path;
	char	*t;
	char	*s;

	i = 0;
	path = ft_split(ft_select(env)+5, ':');
	while (path[i])
	{
		t = f_slach(str);
		s = ft_strjoin(path[i], t);
		if (!access(s, X_OK))
		{
			frepath(path);
			return (free(t), s);
		}
		free(t);
		free(s);
		i++;
	}
	frepath(path);
	return (NULL);
}
