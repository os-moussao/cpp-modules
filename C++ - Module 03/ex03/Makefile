NAME   = diamond
CFLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98
CC     = c++
RM     = rm -f

SRC    = ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp main.cpp
OBJS   = $(SRC:%.cpp=%.o)
HEADERS = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: clean all
