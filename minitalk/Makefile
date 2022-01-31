
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c \
	   client.c

OBJS = ${SRCS:.c=.o}

CLIENT = client
SERVER = server
LIBFT = libft/libft.all
FT_PRINTF = ft_printf/printf.a
LIBFT_PATH = ./libft/
FT_PRINTF_PATH = ./ft_printf/

AR = ar rc
RM = rm -f

all: ${SERVER} ${CLIENT}

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(CLIENT): $(FT_PRINTF) $(LIBFT) client.o minitalk.h
	$(CC) -o client client.o $(LIBFT) $(FT_PRINTF)

$(SERVER): $(FT_PRINTF) $(LIBFT) server.o minitalk.h
	$(CC) -o server server.o $(LIBFT) $(FT_PRINTF)

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	${RM} ${SERVER} ${SERVER}
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
