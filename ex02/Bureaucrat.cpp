//CABECERA

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("random"), _grade(150){}

Bureaucrat::Bureaucrat( Bureaucrat const &b ): _name(b._name), _grade(b._grade)
{
	this->_checkRange( this->_grade );
}

Bureaucrat::Bureaucrat( int grade ): _name("random"), _grade(grade)
{
	this->_checkRange( this->_grade );
}

Bureaucrat::~Bureaucrat( void ){}

Bureaucrat		&Bureaucrat::operator=( Bureaucrat const &b )
{
	if ( this != &b )
	{
		this->_checkRange( this->_grade );
		this->_grade = b._grade;
	}
	return ( *this );
}

void			Bureaucrat::_checkRange( int grade )
{
	std::ostringstream	oss;

	oss << grade;
	std::string str_grade = "Bureauctrat '" + this->_name + "' grade " + \
		oss.str() + " is out of range.";

	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException( "Grade too high: " + str_grade );
	else if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException( "Grade too low: " + str_grade );
}

std::string const	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int		Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void			Bureaucrat::setGrade( int grade )
{
	this->_checkRange( grade );
	this->_grade = grade;
}

void			Bureaucrat::incrementGrade( void )
{
	this->_checkRange( this->_grade  - 1);
	this->_grade --;
}

void			Bureaucrat::decrementGrade( void )
{
	this->_checkRange( this->_grade + 1 );
	this->_grade ++;
}

void			Bureaucrat::signForm( Form &f)
{
	bool	already_signed;

	already_signed = f.getSigned();
	
	if ( true == already_signed )
	{
		std::cout << CYAN << this->_name << " couldn't sign " \
			<< f.getName() << " because it is already signed." \
			<< RESET << std::endl;
	}
	else
	{
		f.beSigned( *this );
		std::cout << GREEN << this->_name << " signed " << f.getName() << RESET << std::endl;
	}
}	

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string& msg ): std::out_of_range(msg){}

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string& msg ): std::out_of_range(msg){}

std::ostream	&operator<<( std::ostream &o, Bureaucrat *b )
{
	std::cout << b->getName() << ", bureaucrat grade " << b->getGrade() << "." << std::endl;
	return ( o );
}

std::ostream	&operator<<( std::ostream &o, Bureaucrat b )
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return ( o );
}
