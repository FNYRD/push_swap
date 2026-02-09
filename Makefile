# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 18:08:32 by jericard          #+#    #+#              #
#    Updated: 2026/02/09 18:08:34 by jericard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I./libft

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INCLUDES = -I./ft_printf

INCLUDES = -I./includes $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

SRCS_DIR = ./srcs

SRCS =	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/validations.c \
		$(SRCS_DIR)/parser.c \
		$(SRCS_DIR)/out_and_free.c \
		$(SRCS_DIR)/swaps.c \
		$(SRCS_DIR)/processor.c \
		$(SRCS_DIR)/pushes.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/rotate_reverse.c \
		$(SRCS_DIR)/targets.c \
		$(SRCS_DIR)/costs.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# bonus: $(LIBFT) $(FT_PRINTF) $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)
# 	@touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME) $(BONUS_NAME) .bonus
#Hay un problema porque no borra los objetos anteriores
re: fclean all

.PHONY: all bonus clean fclean re

.SILENT: