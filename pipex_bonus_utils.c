/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:41:38 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/04 14:02:55 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("Cant' Not creat pipe ");
		exit(errno);
	}
	else
		return (0);
}

int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Cant ' Not creat fork");
		exit(errno);
	}
	else
		return (pid);
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
