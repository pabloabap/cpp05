/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:08:42 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:08:47 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat_tests.hpp"

/** Default form and default bureaucrat ( all grades equal to 150 ).
 * Try to sign twice the same form.
 * EXPECTED: Warning message of already signed in the second sign try.
*/
void	testDefBurDefForm( void )
{
	Bureaucrat	*a = new Bureaucrat();
	Form		*f = new Form();
	
	std::cout << PINK << "*** testDefBurDefForm called *** " << RESET << std::endl;
	try
	{
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Default form and bureaucrat in range.
 * Try to sign twice the same form.
 * EXPECTED: Warning message of already signed in the second sign try.
*/
void	testRangeBurDefForm( void )
{
	Bureaucrat	*a = new Bureaucrat( 10 );
	Form		*f = new Form();
	
	std::cout << PINK << "*** testRangeBurDefForm called *** " << RESET << std::endl;
	try
	{
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Default form and bureaucrat out of range, lower value.
 * EXPECTED: Too low exception.
*/
void	testTooLowBurDefForm( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testTooLowBurDefForm called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat( 160 );
		f = new Form();
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Default form and bureaucrat out of range, higher value.
 * EXPECTED: Too high exception.
*/
void	testTooHighBurDefForm( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testTooHighBurDefForm called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat( 0 );
		f = new Form();
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Bureaucrat grade high than sign but low than exec.
 * EXPECTED: Warining on second try sign.
*/
void	testSignableNotExec( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testSignableNotExec called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat( 100 );
		f = new Form("SIGNABLE", 120, 10);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Bureaucrat grade high than sign and exec.
 * EXPECTED: Warining on second try sign.
*/
void	testSignableAndExec( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testSignableNotExec called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat( 100 );
		f = new Form("SIGNABLE", 120, 120);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Bureaucrat grade high than exec but sign.
 * EXPECTED: Exception on sign.
*/
void	testExecButNotSign( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testExecButNotSign called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat( 100 );
		f = new Form("SIGNABLE", 20, 120);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}
