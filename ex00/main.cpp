/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:54:55 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 16:55:30 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED	"\033[1;38;5;9m"
#define GREEN	"\033[1;38;5;10m"
#define YELLOW	"\033[1;38;5;11m"
#define RESET	"\033[0m"

#include "Bureaucrat.hpp"
#include <iostream>

static void tryCatchRight( Bureaucrat  a );
static void tryCatchValueConstructor( int grade );
static void tryCatchTooLower( Bureaucrat  a );
static void tryCatchTooHigh( Bureaucrat  a );
static void tryCatchConstructor( Bureaucrat a );

int main(void)
{
	Bureaucrat *a = new Bureaucrat();


	tryCatchRight( *a );
	tryCatchValueConstructor( -1 );
	tryCatchValueConstructor( 151 );
	a->setGrade( 150 );
	tryCatchTooLower( *a );
	a->setGrade( 1 );
	tryCatchTooHigh( *a );
	tryCatchConstructor( *a );
	delete a;
	return ( 0 );
}

static void tryCatchRight( Bureaucrat a )
{
	try
	{
		std::cout << "INITIAL BUREAUCRAT VALUES: " << a << std::endl;
		std::cout << "Incrementing until top grade ..." << std::endl;
		while ( a.getGrade() > 1)
			a.incrementGrade();
		std::cout << "BUREAUCRAT VALUES: " << a << std::endl;
		std::cout << "Decrementing until lower grade ..." << std::endl;
		while ( a.getGrade() < 150)
			a.decrementGrade();
		std::cout << "BUREAUCRAT VALUES: " << a << std::endl; 
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}	
}

static void tryCatchValueConstructor( int grade )
{
	Bureaucrat *p = NULL;

	try
	{
		std::cout << "-----------------------------\n" \
			<< "Trying to create a Bureaucrat with grade " \
			<< grade << "(out of range)." << std::endl;
		p = new Bureaucrat(grade); 
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}	
	if ( p )
		delete p;
}

static void tryCatchTooLower( Bureaucrat a )
{
	try
	{
		std::cout << "-----------------------------\n" \
			<< "BUREAUCRAT VALUES: " << a \
			<< "-> Decrementing out of range" << std::endl;
		a.decrementGrade();
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}	
	std::cout << YELLOW << "BUREAUCRAT VALUES AFTER OPERATION: " << a << RESET
			<< "-----------------------------\n" << std::endl;
}

static void tryCatchTooHigh( Bureaucrat a )
{
	try
	{
		std::cout << "-----------------------------\n" \
			<< "BUREAUCRAT VALUES: " << a \
			<< "-> Incrementing out of range" << std::endl;
		a.incrementGrade();
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}	
	std::cout << YELLOW << "BUREAUCRAT VALUES AFTER OPERATION: " << a << RESET
			<< "-----------------------------\n" << std::endl;
}

static void tryCatchConstructor( Bureaucrat a )
{
	try
	{
		Bureaucrat b(a);
		std::cout << "BUREAUCRAT VALUES: " << b << std::endl;
		b = a;
		std::cout << "BUREAUCRAT VALUES: " << b << std::endl;
		std::cout << "BUREAUCRAT VALUES: " << a \
			<< "-----------------------------\n" \
			<< "-> Setting and constructing out of range" << std::endl;
		a.setGrade( 0 );
		b = a;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}	
	std::cout << YELLOW << "BUREAUCRAT VALUES AFTER OPERATION: " << a << RESET
			<< "-----------------------------\n" << std::endl;
}
