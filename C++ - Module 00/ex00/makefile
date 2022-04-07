NAME   = megaphone
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM     = rm -f

all: $(NAME)

$(NAME): megaphone.cpp
	g++ $(CFLAGS) $< -o $@

fclean:
	rm -f megaphone

re: clean all