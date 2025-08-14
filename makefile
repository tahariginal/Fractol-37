SRCS = src/events.c\
	   src/fcts_maths.c\
	   src/init.c\
	   src/main.c\
	   src/rendering.c\
	   src/helper_fct00.c\
	   src/helper_fct01.c\

OBJS = $(SRCS:.c=.o)

NAME = fractol

CC	 = cc

CFLAGS	= -O3 -Wall -Wextra -Werror -Imlx

RM	= rm -rf

all: $(NAME)
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/local/include -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
