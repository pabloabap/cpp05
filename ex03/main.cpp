/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:29 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:13:37 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED	"\033[1;38;5;9m"
#define GREEN	"\033[1;38;5;10m"
#define YELLOW	"\033[1;38;5;11m"
#define PINK	"\033[1;38;5;13m"
#define RESET	"\033[0m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "intern_tests.hpp"
#include <iostream>

int main(void)
{
	testInterns();
	return ( 0 );
}
