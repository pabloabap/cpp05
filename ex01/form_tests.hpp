/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:18 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:09:23 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_TESTS_HPP
# define FORM_TESTS_HPP

# define RED	"\033[1;38;5;9m"
# define GREEN	"\033[1;38;5;10m"
# define YELLOW	"\033[1;38;5;11m"
# define PINK	"\033[1;38;5;13m"
# define RESET	"\033[0m"

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

void	testFormFunctions( void );
void	testRangeFormDefBur( void );
void	testHighSign( void );
void	testHighExec( void );

void	testSingTooHigher( void );
void	testSingTooLower( void );
void	testExecTooHigher( void );
void	testExecTooLower( void );

#endif
