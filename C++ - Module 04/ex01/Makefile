NAME   = brain
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

SRC    = Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp
OBJS   = $(SRC:%.cpp=%.o)
HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp

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
