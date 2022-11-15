# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:54:38 by smayrand          #+#    #+#              #
#    Updated: 2022/11/15 12:55:15 by smayrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[32m'
NONE = '\033[0m'

NAME = minishell

CC = gcc -g 
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs

RM = rm -f

all:
	@afplay ./srcs/sounds/th.wav
	@echo " ==============="
	@echo $(GREEN) "FULLY	COMPILED" $(NONE)
	
$(NAME):

clean:
	@$(RM) $(OBJS)

fclean: clean
	@afplay ./srcs/sounds/cry.wav
	@$(RM) $(NAME)
	@echo $(GREEN) "FULLY	CLEANED" $(NONE)

rick:
	@curl -s -L http://bit.ly/10hA8iC | bash
	
re: fclean all