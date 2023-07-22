NAME   = RPN
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

SRC    = main.cpp RPN.cpp
OBJS   = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.cpp RPN.hpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: clean all
