# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 14:30:02 by lelhlami          #+#    #+#              #
#    Updated: 2022/02/11 10:44:21 by lelhlami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH  = srcs

OBJ_PATH  = objs

LIBFT_SRC = include/libft

SOURCES = 	main.c \
			extra_mlx.c \
			hook.c \
			mandelbrot.c \
			color.c\
			fractol.c \
			Julia.c \
			Fern.c \
			tricorn.c

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))

OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

HEADER = fractol.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m


all: lib tmp $(NAME) 

lib:
	@echo "$(GREEN)Creating libft files$(CYAN)"
	@make -C $(LIBFT_SRC)

$(NAME): $(OBJS)
	@$(CC) $(MLX_FLAGS) $(FLAGS) $(LIBFT_SRC)/libft.a $(OBJS) -o $@ 
	@echo "$(GREEN)Project successfully compiled"
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c include/$(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

tmp:
	@mkdir -p objs

bonus : all

%.o : %.c
	@$(CC) $(FLAGS) -c $<
clean:
	@echo "$(VIOLET)Deleting Libft library files$(CYAN)"
	@make clean -C $(LIBFT_SRC)
	@echo "$(VIOLET)Deleting Fractol library files$(CYAN)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: tmp, re, fclean, clean, bonus, lib, all
