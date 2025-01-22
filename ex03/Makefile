# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 17:13:37 by pabad-ap          #+#    #+#              #
#    Updated: 2025/01/22 17:13:41 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat

CPP		= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= Bureaucrat.hpp \
		AForm.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp \
		intern_tests.hpp

SRC		= main.cpp \
		intern_tests.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

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
