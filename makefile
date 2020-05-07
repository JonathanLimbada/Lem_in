MAKELIB = -C libft
LIB = libft/libft.a
LI = lem_in
FLAGS = -Wall -Werror -Wextra
LISRC = lem_in.c \
src/validation/ants.c \
src/validation/comments.c \
src/validation/end.c \
src/validation/links.c \
src/validation/rooms.c \
src/validation/start.c \
src/validation.c \
src/init.c \
src/free.c \
src/print.c \
src/algo/map.c \
		$(LIB)

all: $(MAKELIB) $(LI)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)
$(LI):
		gcc $(FLAGS) $(LISRC) -o $(LI)

clean:
	rm -fr $(LI)
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f libft/libft.a

re: clean all