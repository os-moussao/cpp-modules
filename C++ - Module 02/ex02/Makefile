NAME   = fixed
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

SRC    = Fixed.cpp main.cpp
OBJS   = $(SRC:%.cpp=%.o)
HEADERS = Fixed.hpp

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
