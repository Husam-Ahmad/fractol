# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 11:22:05 by huahmad           #+#    #+#              #
#    Updated: 2025/02/14 17:07:36 by huahmad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wextra -Werror -Wall -g
LIBMLX = MLX
MLXFLAGS = ./minilibx-linux/libmlx.a -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
cc = cc
INCLUDES = -I $(LIBMLX)/include
SRCS = fractol.c \
		setup.c \
		hooking.c \
		imgbyimg.c \
		julia.c \

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) -lm $(SRCS) $(LIBFT) $(MLXFLAGS)  -o $(NAME)
	echo "ready"

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SRCS:.c=.o)
	echo "OBJs were deleted"

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -rf $(NAME) && echo "$(NAME) was deleted"
	rm -f *:Zone.Identifier
	

re: clean all

.PHONY: all, clean, fclean, re, libmlx
