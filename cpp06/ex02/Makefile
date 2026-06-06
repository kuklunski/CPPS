NAME = base
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
Src_Files = main.cpp Base.cpp
Object_files= $(Src_Files:.cpp=.o)

all : $(NAME)

$(NAME) : $(Object_files)
	$(CC) $(CFLAGS) $(Object_files) -o $(NAME)

%.o:%.cpp Base.hpp A.hpp B.hpp C.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(Object_files)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re