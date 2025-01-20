#include "Form.hpp"

Form::Form( void ): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form( std::string &name, int gradeToSign, int gradeToExecute ): _name(name), _signed(false), \
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{

}

Form::Form( Form const &f ): _name(f._name), _signed(f._signed), \
	_gradeToSign(f._gradeToSign), _gradeToExecute(f._gradeToExecute){}

Form::~Form( void ){}

Form	&Form::operator=( Form const &f )
{
	if ( this != &f )
		this->_signed = f._signed;
	return ( *this );
}

Form::GradeTooHighException::GradeTooHighException( const std::string &msg): std::out_of_range(msg){}

Form::GradeTooLowException::GradeTooLowException( const std::string &msg): std::out_of_range(msg){}

std::string	Form::getName( void )
{
	return ( this->_name );
}

bool		Form::getSigned( void )
{
	return ( this->_signed );
}

int	Form::getGradeToSign( void )
{
	return ( this->_gradeToSign );
}

int	Form::getGradeToExecute( void )
{
	return ( this->_gradeToExecute );
}

void		Form::beSigned( Bureaucrat const &b )
{
	if ( b.getGrade() > this->_gradeToSign )
		throw Form::GradeTooHighException(\
			b.getName() + " couldn't sign " + this->_name \
			+ " because is lower than form grade to sign.");
	else if ( this->_signed == false && b.getGrade() <= this->_gradeToSign )
	{
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->_name;
	}
	else
		std::cout << PURPLE << b.getName() << " couldn't sign " << this->_name \
			<< " because it is already signed." << RESET << std::endl;
}

std::ostream	&operator<<( std::ostream &o, Form *f )
{
	std::cout << "___FORM " << f->getName() << " INFORMATION___\n" \
		<< std::cout.width(20) << "|- NAME: " << f->getName() << "\n" \
		<< std::cout.width(20) << "|- SIGNED: " << f->getSigned() << "\n" \
		<< std::cout.width(20) << "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n" \
		<< std::cout.width(20) << "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << std::endl;
	return ( o );		
}

