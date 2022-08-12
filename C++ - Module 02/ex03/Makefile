NAME   = bsp
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

SRC    = Fixed.cpp Point.cpp main.cpp bsp.cpp
OBJS   = $(SRC:%.cpp=%.o)
HEADERS = Fixed.hpp Point.hpp

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
