/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:03:10 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 18:55:23 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>

int	o_file(char *f, int op)
{
	int	ret;

	ret = 0;
	if (op == 1)
	ret = open(f, O_RDONLY, 0777);
	if (op == 2)
	ret = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret < 0)
	{
		perror("I/O File_Not_Found");
		exit(errno);
	}
	return (ret);
}

void	child(char **argv, char **env, int *fds)
{
	char	**cmd;
	int		filein;
	char	*str;

	(void) fds;
	str = pathcmd(argv[2], env);
	filein = o_file(argv[1], 1);
	cmd = ft_split(argv[2], ' ');
	dup2(fds[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fds[0]);
	if (execve(str, cmd, env) == -1)
	{
		perror("Command_Not_found");
		exit(EXIT_FAILURE);
	}
}

void	parent(char **argv, char **env, int *fds)
{
	char	**cmd;
	int		fileout;
	char	*str;

	(void) fds;
	str = pathcmd(argv[3], env);
	cmd = ft_split(argv[3], ' ');
	fileout = o_file(argv[4], 2);
	dup2(fds[0], STDIN_FILENO);
	dup2(STDOUT_FILENO, fds[0]);
	dup2(fileout, STDOUT_FILENO);
	close(fds[1]);
	if (execve(str, cmd, env) == -1)
	{
		perror("Command_Not_found");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	int		pid1;
	int		pid2;

	if (argc == 5)
	{
		ft_pipe(fds);
		pid1 = ft_fork();
		if (pid1 == 0)
		{
			child(argv, env, fds);
		}
		pid2 = ft_fork();
		if (pid2 == 0)
		{
			parent(argv, env, fds);
		}
		close(fds[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		perror("Number of parameters Not correct");
}
