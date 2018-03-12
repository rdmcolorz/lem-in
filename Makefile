# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:07:38 by tyang             #+#    #+#              #
#    Updated: 2018/03/11 18:33:41 by tyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c \
			error_msg.c \
			parse_file.c \
		
OBJ = $(SOURCE:.c=.o)

$(NAME):
	#@echo "Compiling Libft";\
	@$(MAKE) re -C libft \
	@$(MAKE) clean -C libft \
	@echo "Cleaned object files";\
	@echo "Compiling lem-in"; 
	@gcc $(FLAGS) $(SOURCE) -Ilibft/includes -L. libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all
