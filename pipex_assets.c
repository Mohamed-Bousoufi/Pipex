/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:48:54 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 17:49:23 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}
