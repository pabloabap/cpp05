/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:01 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:09:05 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# define CYAN "\033[0;38;5;14m"
# define RESET "\033[0m"
# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeToSign;
		int const		_gradeToExecute;

		void			_checkRange( void ) const;
	public:
		Form( void );
		Form( std::string const &name, int gradeToSign, int gradeToExecute );
		Form( Form const &f );
		~Form( void );

		Form	&operator=( Form const &f );
		
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException( const std::string &msg);
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException( const std::string &msg);
		};
		std::string const	&getName( void ) const;
		bool const		&getSigned( void ) const;
		int const		&getGradeToSign( void ) const;
		int const		&getGradeToExecute( void ) const;

		void		beSigned( Bureaucrat const &b );		
				
};

std::ostream	&operator<<( std::ostream &o, Form *f );
std::ostream	&operator<<( std::ostream &o, Form &f );

#endif
