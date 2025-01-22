//CABECERA

#include "form_tests.hpp"

static void operations( std::string burType, Bureaucrat b, ShrubberyCreationForm s, \
	RobotomyRequestForm r, PresidentialPardonForm p );
static void executeUnsigned( Bureaucrat top );

/** Checking all AForm Derived classes work as expected and manage
 * AForms with Bureaucrats of different hierarchy.
 * EXPECTED: Exceptions on actions of bureaucrats of lower hierarchy level tan
 * AForm level, successful operations in other cases.
 */

void testAFormDeriveds( void )
{
	ShrubberyCreationForm	s("S_TARGET");
	RobotomyRequestForm	r("R_TARGET");
	PresidentialPardonForm	p("P_TARGET");
	Bureaucrat	top(1);
	Bureaucrat	rob(70);
	Bureaucrat	shr(140);
	Bureaucrat	pll(150);

	std::cout << PINK << "*** testAFormDeriveds called *** " << RESET << std::endl;
	std::cout << "__________FORMS__________\n" << s << r << p 
		<< "__________BUREAUCRATS__________\n" << top << rob \
		<< shr << pll << std::endl;
	
	std::cout << "GET NAME - " << s.getName() << "\n"
		<< "GET SIGNED - " << s.getSigned() << "\n"
		<< "GET G2SIGN - " << s.getGradeToSign() << "\n"
		<< "GET G2EXEC - " << s.getGradeToExecute() << "\n"
		<< "GET GTARGET - " << s.getTarget() << std::endl;
	operations("Top",  top, s, r, p );
	operations("Rob", rob, s, r, p );
	operations("Shr", shr, s, r, p );
	operations("Pll", pll, s, r, p );
	executeUnsigned( top );
}

static void operations( std::string burType, Bureaucrat b, ShrubberyCreationForm s, \
	RobotomyRequestForm r, PresidentialPardonForm p )
{
	std::cout << PINK << "*** test" << burType
		<< "Operations called *** " << RESET << std::endl;
	try
	{
		b.signForm(s);
		b.executeForm(s);
	}
	catch ( const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}

	try
	{
		b.signForm(r);
		b.executeForm(r);
		b.executeForm(r);
		b.executeForm(r);
		b.executeForm(r);
	}
	catch ( const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try
	{
		b.signForm(p);
		b.executeForm(p);
	}
	catch ( const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
}

static void executeUnsigned( Bureaucrat top )
{
	std::cout << PINK << "*** testExecuteUnsigned called *** " << RESET << std::endl;
	ShrubberyCreationForm	a;
	
	try
	{
		top.executeForm(a);
	}
	catch ( const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
}
