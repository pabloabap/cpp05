/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:11:35 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:11:39 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): \
	AForm( "Presidential", 25, 5 ), _target("target"){}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ): \
	AForm( "Presidential", 25, 5 ), _target(target){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &f ): \
	AForm( f.getName(), f.getGradeToSign(), f.getGradeToExecute() ), _target(f._target){}

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &f )
{
	if ( this != &f)	
	{
		this->_target = f._target;
		AForm::operator=(f);
	}
	return ( *this );
}

std::string const	&PresidentialPardonForm::getTarget( void ) const
{
	return ( this->_target );
}

void			PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	std::ostringstream	executeGrade;
	std::ostringstream	bureauctratGrade;
	std::string		msg;

	executeGrade << this->getGradeToExecute();	
	bureauctratGrade << executor.getGrade();	
	if ( false == this->getSigned() )
	{
		std::cout << CYAN << this->getName() << " not signed. Sign "
			<< "the documment before execute it." << RESET << std::endl;
	}
	else if ( executor.getGrade() > this->getGradeToExecute() )
	{
		msg = "Grade too low: Bureaucrat grade " + bureauctratGrade.str() \
			+ " is lower than required grade to execute " \
			+ this->getName() + "(" + executeGrade.str() + ")";
		throw AForm::GradeTooLowException( msg );
	}
	else
	{
		std::cout << GREEN << this->_target 
			<< " has been pardoned by Zaphod Beeblebrox."
			<< RESET << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm *f )
{
	std::cout << "___PRESIDENTIAL FORM " << f->getName() << " INFORMATION___\n"
		<< "|- NAME: " << f->getName() << "\n"
		<< "|- SIGNED: " << f->getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << "\n"
		<< "|- TARGET: " << f->getTarget() << std::endl;
	return ( o );		
}

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm &f )
{
	std::cout << "___PRESIDENTIAL FORM " << f.getName() << " INFORMATION___\n"
		<< "|- NAME: " << f.getName() << "\n"
		<< "|- SIGNED: " << f.getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f.getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f.getGradeToExecute() << "\n"
		<< "|- TARGET: " << f.getTarget() << std::endl;
	return ( o );		
}

