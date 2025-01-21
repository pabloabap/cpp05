//CABECERA

#include "Form.hpp"

Form::Form( void ): _name("default form"), _signed(false), _gradeToSign(150), \
	_gradeToExecute(150)
{
	this->_checkRange();
}

Form::Form( std::string const &name, int gradeToSign, int gradeToExecute ): \
	_name(name), _signed(false), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute)
{
	this->_checkRange();
}

Form::Form( Form const &f ): _name(f._name), _signed(f._signed), \
	_gradeToSign(f._gradeToSign), _gradeToExecute(f._gradeToExecute)
{
	this->_checkRange();
}

Form::~Form( void ){}

Form	&Form::operator=( Form const &f )
{
	if ( this != &f )
	{
		this->_checkRange();
		this->_signed = f._signed;
	}
	return ( *this );
}

void			Form::_checkRange( void ) const
{
	std::ostringstream	signGrade;
	std::ostringstream	executeGrade;
	std::string		msg;

	signGrade << this->_gradeToSign;
	executeGrade << this->_gradeToExecute;
	if ( this->_gradeToSign > 150 )
	{
		msg = "Grade too low: " + this->_name + " form sign grade " \
			+ signGrade.str() + " is out of range 1-150.";
		throw Form::GradeTooLowException( msg );
	}
	if ( this->_gradeToSign < 1 )
	{	
		msg =  "Grade too high: " + this->_name + " form sign grade " \
			+ signGrade.str() + " is out of range 1-150.";
		throw Form::GradeTooHighException( msg );
	}
	if ( this->_gradeToExecute > 150 )
	{
		 msg = "Grade too low: " + this->_name + " form execute grade " \
			+ executeGrade.str() + " is out of range 1-150.";
		throw Form::GradeTooLowException( msg );
	}
	if ( this->_gradeToExecute < 1 )
	{
		msg = "Grade too high: " + this->_name + " form execute grade " \
			+ executeGrade.str() + " is out of range 1-150.";
		throw Form::GradeTooHighException( msg );
	}
}

Form::GradeTooHighException::GradeTooHighException( const std::string &msg): std::out_of_range(msg){}

Form::GradeTooLowException::GradeTooLowException( const std::string &msg): std::out_of_range(msg){}

std::string const	&Form::getName( void ) const
{
	return ( this->_name );
}

bool const		&Form::getSigned( void ) const
{
	return ( this->_signed );
}

int const		&Form::getGradeToSign( void ) const
{
	return ( this->_gradeToSign );
}

int const		&Form::getGradeToExecute( void ) const
{
	return ( this->_gradeToExecute );
}

void		Form::beSigned( Bureaucrat const &b )
{
	if ( b.getGrade() > this->_gradeToSign )
		throw Form::GradeTooLowException("Grade too low: " \
			+ b.getName() + " couldn't sign " + this->_name \
			+ " because its grade is lower than required to sign.");
	else if ( this->_signed == false )
	{
		this->_signed = true;
	}
}

std::ostream	&operator<<( std::ostream &o, Form *f )
{
	std::cout << "___FORM " << f->getName() << " INFORMATION___\n" \
		<< "|- NAME: " << f->getName() << "\n" \
		<< "|- SIGNED: " << f->getSigned() << "\n" \
		<< "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n" \
		<< "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << std::endl;
	return ( o );		
}

std::ostream	&operator<<( std::ostream &o, Form &f )
{
	std::cout << "___FORM " << f.getName() << " INFORMATION___\n" \
		<< "|- NAME: " << f.getName() << "\n" \
		<< "|- SIGNED: " << f.getSigned() << "\n" \
		<< "|- GRADE TO SIGN: " << f.getGradeToSign() << "\n" \
		<< "|- GRADE TO EXECUTE: " << f.getGradeToExecute() << std::endl;
	return ( o );		
}
