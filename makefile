MAKELIB = -C libft
LIB = libft/libft.a
FLAGS = -Wall -Werror -Wextra

all: $(MAKELIB) $(CR) $(PS)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)

clean:
	rm -f libft/*.o

fclean: clean
	rm -f libft/libft.a

re: clean all