/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:42:55 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/04 15:33:08 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

char	*pathcmd(char *argv, char **env);
void	frepath(char **cmd);
char	*ft_select(char **path);
char	*f_slach(char *ar);
int		o_file(char *f, int op);
char	*ft_malloc(int size);
int		ft_fork(void);
int		ft_pipe(int fd[2]);

#endif