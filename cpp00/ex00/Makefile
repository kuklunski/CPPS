NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
Objects = megaphone.o
Src_Files = $(Src_Files:.cpp=.o)

all : $(NAME)

$(NAME) : $(Objects)
	$(CC) $(CFLAGS) $(Objects) -o $(NAME)

clean :
	rm -f $(Objects)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re