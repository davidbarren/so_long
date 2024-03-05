# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 12:05:08 by dbarrene          #+#    #+#              #
#    Updated: 2024/03/05 16:54:32 by dbarrene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

LIBFTPATH = ./libft

LIBFT = $(LIBFTPATH)/libft.a

LIBMLX	:= ./MLX42

HEADERS	:= -I $(LIBMLX)/include

SRCS = main.c\
errors.c\
element_counters.c\
path_helpers.c\
map_reading.c\
load_textures.c\
game_init.c\
player_movement.c\
place_map.c

OBJS= $(SRCS:.c=.o)

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
$(OBJS): $(SRCS)
	cc -Wall -Wextra -Werror -c $(@:.o=.c) -o $@

$(LIBFT):
	make -C $(LIBFTPATH)

$(NAME): $(LIBFT) $(OBJS)
	cc -Wall -Wextra -Werror $(SRCS) $(LIBS) $(HEADERS) $(LIBFT) -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)
	@rm -rf $(LIBMLX)/build

re: fclean libmlx $(NAME)

.PHONY: all, clean, fclean, libmlx, re
