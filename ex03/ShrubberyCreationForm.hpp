//CABECERA

#ifndef SHRUBBERY_CLASS_HPP
# define SHRUBBERY_CLASS_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &f );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &f );
		
		std::string const	&getTarget( void ) const;
		void			execute( Bureaucrat const &executor ) const;
};

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *f );
std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm &f );

#endif
