# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduffey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 12:30:18 by jduffey           #+#    #+#              #
#    Updated: 2019/09/13 13:35:01 by jduffey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES  = src/*.c \
	get_next_line.c

CFLAGS = -Wall -Werror -Wextra

OBJ = *.o

all: $(NAME)

$(NAME): 
	gcc -c $(CFLAGS) $(FILES)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
