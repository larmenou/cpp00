CPP			:= c++
CFLAGS		:= -g -Wall -Wextra -Werror -std=c++98

NAME		:= phonebook

SRCS_F		:= 	main \
				Contact \
				PhoneBook

SRCS		:= $(addsuffix .cpp, $(SRCS_F))
OBJ			:= $(addsuffix .o, $(SRCS_F))

all: 		$(NAME)

$(NAME): 	$(OBJ)
				$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
				@rm -f $(OBJ)

fclean:		clean
				@rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re