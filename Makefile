# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:07:38 by tyang             #+#    #+#              #
#    Updated: 2018/03/22 03:18:09 by tyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c \
			error_msg.c \
			file.c \
			init.c \
			free.c \
			create.c \
			links.c \
			utilities.c \
			utilities2.c \
			ft_list_queue.c \
			list_rev.c \
			bfs.c \
			print_path.c \
			path.c \
			assign.c \
	
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling Libft";
	@$(MAKE) re -C libft;
	@$(MAKE) clean -C libft;
	@echo "Cleaned object files";
	@echo "Compiling lem-in";
	@gcc $(FLAGS) $(SOURCE) -Ilibft/includes -L. libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all

debug:
	@rm -f $(NAME)
	@gcc $(FLAGS) -g -fsanitize=address $(SOURCE) -Ilibft/includes \
	-L. libft/libft.a -o $(NAME)
