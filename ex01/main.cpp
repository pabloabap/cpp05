/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:23 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:09:27 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED	"\033[1;38;5;9m"
#define GREEN	"\033[1;38;5;10m"
#define YELLOW	"\033[1;38;5;11m"
#define PINK	"\033[1;38;5;13m"
#define RESET	"\033[0m"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "bureaucrat_tests.hpp"
#include "form_tests.hpp"
#include <iostream>

int main(void)
{
	testDefBurDefForm();
	testRangeBurDefForm();
	testTooLowBurDefForm();
	testTooHighBurDefForm();
	testSignableNotExec();
	testSignableAndExec();
	testExecButNotSign();

	testFormFunctions();
	testRangeFormDefBur();
	testHighSign();
	testHighExec();
	testSingTooHigher();
	testSingTooLower();
	testExecTooHigher();
	testExecTooLower();
	return ( 0 );
}
