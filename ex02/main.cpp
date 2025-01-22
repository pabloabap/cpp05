//CABECERA

#define RED	"\033[1;38;5;9m"
#define GREEN	"\033[1;38;5;10m"
#define YELLOW	"\033[1;38;5;11m"
#define PINK	"\033[1;38;5;13m"
#define RESET	"\033[0m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "form_tests.hpp"
#include <iostream>

int main(void)
{
	testAFormDeriveds();
	return ( 0 );
}
