#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("random"), _grade(150){}

Bureaucrat::Bureaucrat( Bureaucrat const &b ): _name(b._name), _grade(b._grade)
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

void			Bureaucrat::_checkRange( unsigned int grade )
{
	std::ostringstream	oss;

	oss << grade;
	std::string str_grade = "Bureauctrat '" + this->_name + "' grade " + \
		oss.str() + " is out of range.";

	if ( grade < 1 )
	{
		this->_grade = 1;
		throw Bureaucrat::GradeTooHighException( str_grade + " Reseted to 1." );
	}
	else if ( grade > 150 )
	{
		this->_grade = 150;
		throw Bureaucrat::GradeTooLowException( str_grade + " Reseted to 150.");
	}
}

std::string const	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

unsigned int		Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void			Bureaucrat::setGrade( unsigned int grade )
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
