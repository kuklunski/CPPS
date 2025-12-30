NAME = Weapons
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re