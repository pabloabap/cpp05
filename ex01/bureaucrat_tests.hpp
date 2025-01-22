/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat_tests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:08:47 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:08:56 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_TESTS_HPP
# define BUREAUCRAT_TESTS_HPP

# define RED	"\033[1;38;5;9m"
# define GREEN	"\033[1;38;5;10m"
# define YELLOW	"\033[1;38;5;11m"
# define PINK	"\033[1;38;5;13m"
# define RESET	"\033[0m"

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

void testDefBurDefForm( void );
void testRangeBurDefForm( void );
void testTooLowBurDefForm( void );
void testTooHighBurDefForm( void );

void	testSignableNotExec( void );
void	testSignableAndExec( void );
void	testExecButNotSign( void );
#endif
