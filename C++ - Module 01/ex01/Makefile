NAME   = zombies
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

SRC    = Zombie.cpp zombieHorde.cpp main.cpp
OBJS   = $(SRC:%.cpp=%.o)
HEADERS = Zombie.hpp zombieHorde.hpp

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
