/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:42:55 by mbousouf          #+#    #+#             */
/*   Updated: 2023/01/01 20:42:19 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS
# define    PIPEX_BONUS

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include "get_next_line/get_next_line.h"

char    *pathcmd(char *argv, char **env);
void    frepath(char ** cmd);
char    *ft_select(char **path);
char    *f_slach(char *ar);
int     o_file(char *f, int op);
char    *ft_malloc(int size);
#endif