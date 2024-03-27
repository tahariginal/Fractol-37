SRCS = events.c\
	   fcts_maths.c\
	   init.c\
	   main.c\
	   rendering.c\
	   helper_fct00.c\
	   helper_fct01.c\

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
