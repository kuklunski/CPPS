Name = ScavTrap
CC = c++
Flags =  -Wall -Wextra -Werror -std=c++98
Src_files = main.cpp ClapTrap.cpp ScavTrap.cpp
Obj_files = $(Src_files:.cpp=.o)

all : $(Name)

$(Name) : $(Obj_files)
	$(CC) $(Flags) $(Obj_files) -o $(Name)

%.o : %.cpp
	$(CC) $(Flags) -c $< -o $@

clean :
	rm -f $(Obj_files)

fclean : clean
	rm -f $(Name)

re : fclean all

.PHONY : all clean fclean re