# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:38:53 by lgenevey          #+#    #+#              #
#    Updated: 2021/11/16 10:16:00 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_positive_putnbr.c \
		ft_count_digit.c \
		ft_case_s.c \
		ft_putbase_fd.c \
		ft_putpointer.c \
		ft_norminette.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
AR = ar rc
RM = rm -f
LIBFT_PATH = $(PARENT_DIR)
all: ${NAME}
${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
