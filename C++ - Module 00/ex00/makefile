NAME   = megaphone
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC     = c++
RM     = rm -f

all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(CFLAGS) $< -o $@

fclean:
	rm -f megaphone

re: clean all