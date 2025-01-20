//CABECERA

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# define PURPLE "\033[0;38;5;14m"
# define RESET "\033[0m"
# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeToSign;
		int const		_gradeToExecute;
	public:
		Form( void );
		Form( std::string &name, int gradeToSign, int gradeToExecute );
		Form( Form const &f );
		~Form( void );

		Form	&operator=( Form const &f );
		
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException( const std::string &msg);
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException( const std::string &msg);
		};
		std::string 		getName( void );
		bool			getSigned( void );
		int			getGradeToSign( void );
		int			getGradeToExecute( void );

		void		beSigned( Bureaucrat const &b );		
				
};

std::ostream	&operator<<( std::ostream &o, Form *f );

#endif
