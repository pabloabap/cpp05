# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 17:08:32 by pabad-ap          #+#    #+#              #
#    Updated: 2025/01/22 17:08:37 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat

CPP		= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= Bureaucrat.hpp Form.hpp bureaucrat_tests.hpp form_tests.hpp

SRC		= main.cpp \
		bureaucrat_tests.cpp \
		form_tests.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

do: $(NAME)
	@clear
	@./$(NAME)

.PHONY: all clean fclean re
