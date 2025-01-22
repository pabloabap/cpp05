/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:54 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:13:58 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_robotomize = true;

RobotomyRequestForm::RobotomyRequestForm( void ): \
	AForm( "Robotomy", 72, 45 ), _target("target"){}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ): \
	AForm( "Robotomy", 72, 45 ), _target(target){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &f ): \
	AForm( f.getName(), f.getGradeToSign(), f.getGradeToExecute() ), _target(f._target){}

RobotomyRequestForm::~RobotomyRequestForm( void ){}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &f )
{
	if ( this != &f)	
	{
		this->_target = f._target;
		AForm::operator=(f);
	}
	return ( *this );
}

std::string const	&RobotomyRequestForm::getTarget( void ) const
{
	return ( this->_target );
}

void			RobotomyRequestForm::execute( Bureaucrat const &executor ) const
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
	else if ( true == RobotomyRequestForm::_robotomize )
	{
		std::cout << GREEN << "DrIlLiNg NOiSE... " << this->_target
			<< " has been robotomized successfully!!" << RESET << std::endl;
		RobotomyRequestForm::_robotomize = false;
	}
	else
	{
		std::cout << RED << this->_target << " robotomy failed!!"
			<< RESET << std::endl;
		RobotomyRequestForm::_robotomize = true;
	}
}

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm *f )
{
	std::cout << "___ROBOTOMY FORM " << f->getName() << " INFORMATION___\n"
		<< "|- NAME: " << f->getName() << "\n"
		<< "|- SIGNED: " << f->getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << "\n"
		<< "|- TARGET: " << f->getTarget() << std::endl;
	return ( o );		
}

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm &f )
{
	std::cout << "___ROBOTOMY FORM " << f.getName() << " INFORMATION___\n"
		<< "|- NAME: " << f.getName() << "\n"
		<< "|- SIGNED: " << f.getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f.getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f.getGradeToExecute() << "\n"
		<< "|- TARGET: " << f.getTarget() << std::endl;
	return ( o );		
}

