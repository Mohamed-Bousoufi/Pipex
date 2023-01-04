/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:40:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/04 15:39:21 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_pipe(char *str, char **cmd, char **env, int *input_fd)
{
	int		pipefd[2];
	pid_t	pid;

	ft_pipe(pipefd);
	pid = ft_fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		dup2(*input_fd, STDIN_FILENO);
		close(*input_fd);
		if (execve(str, cmd, env) == -1)
		{
			perror("Command_not_found");
			exit(errno);
		}
	}
	else
	{
		close(pipefd[1]);
		close(*input_fd);
		*input_fd = pipefd[0];
	}
}

void	ft_last(int a, char **argv, char **env, int *input_fd)
{
	pid_t	pid;
	int		out_fd;
	char	*str;
	char	**cmd;

	pid = fork();
	if (pid == 0)
	{
	str = pathcmd(argv[a - 2], env);
	cmd = ft_split(argv[a - 2], ' ');
	out_fd = o_file(argv[a -1], 2);
		dup2(*input_fd, STDIN_FILENO);
		dup2(out_fd, STDOUT_FILENO);
		close(*input_fd);
		if (execve(str, cmd, env) == -1)
		{
			perror("last_command");
			exit(errno);
		}
	}
	else
	{
		unlink("file");
		waitpid(pid, 0, 0);
	}
}

int	herdoc(char **argv)
{
	int		i;
	int		fd;
	char	*s;
	char	*n;

	n = ft_malloc(BUFFER_SIZE);
	i = 0;
	while (1)
	{
		s = get_next_line(0);
		if (ft_strncmp(s, argv[2], ft_strlen(argv[2])) == 0)
		{
			if (ft_strlen(s) == ft_strlen(argv[2]) + 1)
			{
				free(s);
				break ;
			}
		}
		free(n);
		n = ft_strjoin(n, s);
		free(s);
	}
	fd = o_file("file", 2);
	write(fd, n, strlen(n));
	return (fd);
}

void	hart(int a, char **argv, char **env, int input_fd)
{
	int		i;
	char	*str;
	char	**p_cmd;

	i = 3;
	if (input_fd == 0)
	{
		i = 2;
		input_fd = o_file(argv[1], 1);
	}
	while (i < a - 2)
	{
		str = pathcmd(argv[i], env);
		p_cmd = ft_split(argv[i], ' ');
		get_pipe(str, p_cmd, env, &input_fd);
		frepath(p_cmd);
		free(str);
		i++;
	}
	ft_last(a, argv, env, &input_fd);
}

int	main(int argc, char **argv, char **env)
{
	int	fd;

	fd = 0;
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
		{
			fd = herdoc(argv);
			fd = o_file("file", 1);
		}
		hart(argc, argv, env, fd);
	}
	else
		perror("Number_command_Not_Correct");
	return (0);
}
