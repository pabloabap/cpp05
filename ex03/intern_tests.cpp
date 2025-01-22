/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:17 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:13:22 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_tests.hpp"

static void operations( Bureaucrat b, AForm *f );

/** Checking all AForm Derived classes work as expected and manage
 * AForms with Bureaucrats of different hierarchy.
 * EXPECTED: Exceptions on actions of bureaucrats of lower hierarchy level tan
 * AForm level, successful operations in other cases.
 */

void testInterns( void )
{
	Intern		pll;
	Bureaucrat	top(1);
	AForm		*s = NULL;
	AForm		*r = NULL;
	AForm		*p = NULL;
	AForm		*f = NULL;
	try 
	{
		std::cout << PINK << "*** test Intern making "
			<< "ShrubberyCreationForm" << RESET << std::endl;
		s = pll.makeForm("ShrubberyCreationForm", "S_TARGET");

		operations( top, s );
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try 
	{
		std::cout << PINK << "*** test Intern making "
			<< "RobotomyRequestForm" << RESET << std::endl;
		r = pll.makeForm("RobotomyRequestForm", "R_TARGET");

		operations( top, r );
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try 
	{
		std::cout << PINK << "*** test Intern making "
			<< "PresidentialPardonForm" << RESET << std::endl;
		p = pll.makeForm("PresidentialPardonForm", "P_TARGET");

		operations( top, p );
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try 
	{
		std::cout << PINK << "*** test Intern making "
			<< "Error Form" << RESET << std::endl;
		f = pll.makeForm("ErrorForm", "E_TARGET");

		operations( top, f );
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	if ( s )
		delete ( s );
	if ( r )
		delete ( r );
	if ( p )
		delete ( p );
	if ( f )
		delete ( f );

}

static void operations( Bureaucrat b, AForm *f )
{
	b.signForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
}
