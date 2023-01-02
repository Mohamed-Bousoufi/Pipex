/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:20:42 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 17:49:53 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	char	*s;
	char	*t;

	i = 0;
	if (env != NULL)
	{
		path = ft_split(ft_select(env) + 5, ':');
		while (path[i])
		{
			t = f_slach(str);
			s = ft_strjoin(path[i], t);
			if (!access(s, X_OK))
			{
				frepath(path);
				return (free (t), s);
			}
			i++;
			free(s);
			free(t);
		}
		frepath(path);
	}
	return (NULL);
}
