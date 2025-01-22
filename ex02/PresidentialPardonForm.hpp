/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:11:39 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:11:42 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_CLASS_HPP
# define PRESIDENTIAL_CLASS_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &f );
		~PresidentialPardonForm( void );

		PresidentialPardonForm	&operator=( PresidentialPardonForm const &f );
		
		std::string const	&getTarget( void ) const;
		void			execute( Bureaucrat const &executor ) const;
};

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm *f );
std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm &f );

#endif
