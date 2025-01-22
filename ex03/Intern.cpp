/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:10 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:13:14 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ){}

Intern::Intern( Intern const &){}

Intern::~Intern( void ){}
		
Intern	&Intern::operator=( Intern const & ){ return ( *this ); }

AForm	*Intern::makeForm( std::string formName, std::string target )
{
	std::string	availableForms[3] = {"ShrubberyCreationForm", \
		"RobotomyRequestForm", "PresidentialPardonForm"};
	int	formNameIndex = 0;
	AForm	*form = NULL;

	while (	formNameIndex < 3 && formName != availableForms[formNameIndex] )
		formNameIndex ++;
	
	switch (formNameIndex)
	{
		case 0:
			form = new ShrubberyCreationForm( target );
			std::cout << GREEN << "Intern maked " << formName 
				<< RESET << std::endl; 
			break;
		case 1:
			form = new RobotomyRequestForm( target );
			std::cout << GREEN << "Intern maked " << formName 
				<< RESET << std::endl; 
			break;
		case 2:
			form = new PresidentialPardonForm( target );
			std::cout << GREEN << "Intern maked " << formName 
				<< RESET << std::endl; 
			break;
		case 3:
			form = NULL;
			throw (Intern::TypeFormError(\
				"TypeFormError: Requested form type doesn't exist"));
			break;
	}
	return ( form );
}

Intern::TypeFormError::TypeFormError( std::string const &msg ): std::invalid_argument( msg){}

