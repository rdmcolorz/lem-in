# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:07:38 by tyang             #+#    #+#              #
#    Updated: 2018/03/13 21:06:44 by tyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c \
			error_msg.c \
			file.c \
			init.c \
			debug.c \
			free.c \
		
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@#@echo "Compiling Libft";\
	@$(MAKE) re -C libft \
	@$(MAKE) clean -C libft \
	@echo "Cleaned object files";\
	@echo "Compiling lem-in"; 
	@gcc $(FLAGS) $(SOURCE) -Ilibft/includes -L. libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all
