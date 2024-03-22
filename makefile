SRCS = events.c\
	   fcts_maths.c\
	   init.c\
	   main.c\
	   rendering.c\
	   string_fcts.c\

OBJS = $(SRCS:.c=.o)

NAME = fractol

CC	 = gcc

CFLAGS	= -Ofast -Imlx -fsanitize=address -g3

RM	= rm -rf

all: $(NAME)
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L. -lmlx -lX11 -lXext -lm -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
#$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/local/include -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
