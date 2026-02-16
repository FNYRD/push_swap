# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jericard <jericard@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 14:41:02 by jericard          #+#    #+#              #
#    Updated: 2025/11/21 14:41:04 by jericard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft

CC = cc

AR = ar rcs

RM = rm -f

srcs =	srcs/ft_count_0xchar.c \
		srcs/ft_ctos.c \
		srcs/ft_datatype.c \
		srcs/ft_dotcase.c \
		srcs/ft_flag.c \
		srcs/ft_hexa.c \
		srcs/ft_manager.c \
		srcs/ft_onlywods.c \
		srcs/ft_padding_helper.c \
		srcs/ft_precision.c \
		srcs/ft_putchar.c \
		srcs/ft_putminzero.c \
		srcs/ft_putstr.c \
		srcs/ft_signalflag.c \
		srcs/ft_skipping.c \
		srcs/ft_stringer.c \
		srcs/ft_typeverify.c \
		srcs/ft_utoa.c \
		srcs/ft_width.c \
		srcs/ft_printf.c

bsrcs =	bsrcs/ft_count_0xchar_bonus.c \
		bsrcs/ft_ctos_bonus.c \
		bsrcs/ft_datatype_bonus.c \
		bsrcs/ft_dotcase_bonus.c \
		bsrcs/ft_flag_bonus.c \
		bsrcs/ft_hexa_bonus.c \
		bsrcs/ft_manager_bonus.c \
		bsrcs/ft_onlywods_bonus.c \
		bsrcs/ft_padding_helper_bonus.c \
		bsrcs/ft_precision_bonus.c \
		bsrcs/ft_putchar_bonus.c \
		bsrcs/ft_putminzero_bonus.c \
		bsrcs/ft_putstr_bonus.c \
		bsrcs/ft_signalflag_bonus.c \
		bsrcs/ft_skipping_bonus.c \
		bsrcs/ft_stringer_bonus.c \
		bsrcs/ft_typeverify_bonus.c \
		bsrcs/ft_utoa_bonus.c \
		bsrcs/ft_width_bonus.c \
		bsrcs/ft_printf_bonus.c


all: $(NAME)

OBJS = $(srcs:.c=.o)

BOBJS = $(bsrcs:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: fclean $(BOBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(BOBJS)
	@touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) .bonus

re: fclean all

.PHONY: clean fclean re all bonus

.SILENT:
