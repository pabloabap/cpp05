//CABECERA

#ifndef ROBOTOMY_CLASS_HPP
# define ROBOTOMY_CLASS_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
		static bool	_robotomize;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &f );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	&operator=( RobotomyRequestForm const &f );
		
		std::string const	&getTarget( void ) const;
		void			execute( Bureaucrat const &executor ) const;
};

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm *f );
std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm &f );

#endif
