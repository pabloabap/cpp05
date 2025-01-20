//CABECEra

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <string>
# include <iostream>
# include <exception>
# include <sstream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int			_grade;
		

		void			_checkRange( int grande );
	public:
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const &b );
		Bureaucrat( int grade );
		~Bureaucrat( void );

		Bureaucrat		&operator=( Bureaucrat const &b );

		std::string const	getName( void ) const;
		int			getGrade( void ) const;
		void			setGrade( int grade );

		void			incrementGrade( void );
		void			decrementGrade( void );

		class			GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException( const std::string& msg );
		};
		class			GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException( const std::string& msg );	
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *b);
std::ostream	&operator<<(std::ostream &o, Bureaucrat b);

#endif
