/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:14 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:13:17 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( Intern const & );
		~Intern( void );
		
		Intern	&operator=( Intern const & );

		AForm	*makeForm( std::string formName, std::string target );
		class 	TypeFormError: public std::invalid_argument
		{
			public:
				TypeFormError( std::string const &msg);
		};
};

#endif
