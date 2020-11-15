NAME	=	lem-in
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

LEMC	=	main.c init.c \
			parse_arg.c free.c \
			valid.c parse_room.c \
			alg_bfs.c ants.c print.c \
			matrix.c paths.c \
			queue.c steps.c \
			check_rooms.c markup.c

LIBDIR	=	libft
LIBINC	=	$(LIBDIR)/inc
LIB		=	$(LIBDIR)/libft.a

LEMH = lem.h

all: $(NAME)

$(LIB): $(LIBDIR)
	make -C $(LIBDIR)

$(NAME): $(LEMC) $(LIB) $(LEMH)
	$(CC) $(FLAGS) -o $(NAME) $(LEMC) $(LIB) -I $(LIBINC)

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
