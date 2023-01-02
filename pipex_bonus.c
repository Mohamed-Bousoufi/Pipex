/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:40:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 17:13:02 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	o_file(char *f, int op)
{
	int	ret;

	ret = 0;
	if (op == 1)
		ret = open(f, O_RDONLY, 0777);
	if (op == 2)
		ret = open(f, O_RDWR|O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
	{
		perror("I/O File_Not_Found");
		exit(errno);
	}
	return (ret);
}

void	ft_pipe(char *str, char **cmd, char **env, int *input_fd)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
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

void ft_last(char *str, char **cmd, char **env, int *input_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
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
		close(*input_fd);
		waitpid(pid,0,0);
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
	free(n);
	return (fd);
}

void	hart(int a, char **argv, char **env, int input_fd)
{
	int		out_fd;
	int		i;
	char	*str;
	char	**p_cmd;

	i = 3;
	if (input_fd == 0)
	{
		i = 2;
		input_fd = o_file(argv[1], 1);
	}
	out_fd = o_file(argv[a -1], 2);
	while (i < a - 2)
	{
		str = pathcmd(argv[i], env);
		p_cmd = ft_split(argv[i], ' ');
		ft_pipe(str, p_cmd, env, &input_fd);
		frepath(p_cmd);
		free(str);
		i++;
	}
	str = pathcmd(argv[a - 2], env);
	p_cmd = ft_split(argv[a - 2], ' ');
	ft_last(str, p_cmd, env, &input_fd, out_fd);
	frepath(p_cmd);
	free(str);
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
	return (0);
}
