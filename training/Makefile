NAME = main
CFLAGS = -Wall -Werror -Wextra
CC = c++
Src_Files = main.cpp
Object_files= $(Src_Files:.cpp=.o)

all : $(NAME)

$(NAME) : $(Object_files)
	$(CC) $(CFLAGS) $(Object_files) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(Object_files)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re