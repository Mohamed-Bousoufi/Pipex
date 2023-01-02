/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:53:20 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/02 17:35:33 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define  PIPEX_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>



char	*pathcmd(char *argv, char **env);
void	frepath(char ** cmd);
char	*ft_select(char **path);
char	*f_slach(char *ar);
int     ft_pipe(int fd[2]);
int     ft_fork(void);
#endif