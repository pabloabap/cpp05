/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:03 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/22 17:12:06 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

# define CYAN "\033[0;38;5;14m"
# define RESET "\033[0m"
# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeToSign;
		int const		_gradeToExecute;

		void			_checkRange( void ) const;
	protected:
		AForm( std::string const &name, int gradeToSign, int gradeToExecute );
	public:
		AForm( void );
		AForm( AForm const &f );
		virtual ~AForm( void );

		AForm	&operator=( AForm const &f );
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

		void			beSigned( Bureaucrat const &b );
		virtual	void		execute( Bureaucrat const &executor ) const = 0;
};

std::ostream	&operator<<( std::ostream &o, AForm const *f );
std::ostream	&operator<<( std::ostream &o, AForm const &f );

#endif
