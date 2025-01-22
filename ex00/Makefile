# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 16:55:04 by pabad-ap          #+#    #+#              #
#    Updated: 2025/01/22 16:55:38 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat

CPP		= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= Bureaucrat.hpp

SRC		= main.cpp Bureaucrat.cpp

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
	@./$(NAME)

.PHONY: all clean fclean re
