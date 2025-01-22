/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:11:22 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:11:28 by pabad-ap         ###   ########.fr       */
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
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

void testAFormDeriveds( void );

#endif
