# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 12:07:37 by mbousouf          #+#    #+#              #
#    Updated: 2023/01/02 17:48:41 by mbousouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT  = libft/libft.a
GNL = get_next_line/GNL.a
CC = cc
CFLAGS =-Wall -Wextra -Werror
AR = ar -rc
PIPEX_H = Pipex.h
FILES =	Pipex.c\
		pipex_utils.c\
		pipex_assets.c
		
BOUNUS_FILES = pipex_bonus.c\
			   pipex_bonus_utils.c\
				
OBJS =$(FILES:.c=.o)

OBJS_BOUNUS =$(BOUNUS_FILES:.c=.o)

all: $(NAME)
 
	

%.o :%.c  $(PIPEX_H) 
	$(CC) $(CFLAGS) -c $<


$(NAME) : $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS)  $(LIBFT) $(OBJS) -o pipex
	

bonus : $(LIBFT_A) $(GNL) $(OBJS_BOUNUS)
		$(CC) $(CFLAGS)  $(LIBFT) $(GNL) $(OBJS_BOUNUS) -o pipex
LIBFT_A:
	make -C libft
GNL_A:
	make -C get_next_line/
clean:
	rm -f $(OBJS) $(OBJS_BOUNUS)

fclean: clean
	rm -f $(NAME) $(bonus)
	
re: fclean all

.PHONY: all fclean re clean make 