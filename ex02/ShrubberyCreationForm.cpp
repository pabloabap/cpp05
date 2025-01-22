//CABECERA

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): \
	AForm( "Shrubbery", 145, 137 ), _target("target"){}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ): \
	AForm( "Shrubbery", 145, 137 ), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &f ): \
	AForm( f.getName(), f.getGradeToSign(), f.getGradeToExecute() ), _target(f._target){}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &f )
{
	if ( this != &f)	
	{
		this->_target = f._target;
		AForm::operator=(f);
	}
	return ( *this );
}

std::string const	&ShrubberyCreationForm::getTarget( void ) const
{
	return ( this->_target );
}

void			ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	std::ostringstream	executeGrade;
	std::ostringstream	bureauctratGrade;
	std::string		msg;

	executeGrade << this->getGradeToExecute();	
	bureauctratGrade << executor.getGrade();	
	if ( false == this->getSigned() )
	{
		std::cout << CYAN << this->getName() << " not signed. Sign "
			<< "the documment before execute it." << RESET << std::endl;
	}
	else if ( executor.getGrade() > this->getGradeToExecute() )
	{
		msg = "Grade too low: Bureaucrat grade " + bureauctratGrade.str() \
			+ " is lower than required grade to execute " \
			+ this->getName() + "(" + executeGrade.str() + ")";
		throw AForm::GradeTooLowException( msg );
	}
	else
	{
		std::string	filename = this->_target + "_shrubbery";
		std::ofstream outfile(filename.c_str());
		if (outfile.fail())
			std::cout << RED << "Unable to create new file." 
				<< " Shrubbery not executed due to file creation error."
				 << RESET << std::endl;
		else
		{
			outfile << "       #### " << std::endl;
			outfile << "      #o#### " << std::endl;
			outfile << "    #####o#### " << std::endl;
			outfile << "   #o#\\#|#/### " << std::endl;
			outfile << "    ###\\|/#o# " << std::endl;
			outfile << "      #}|{# " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile.close();
			std::cout << GREEN << executor.getName() << " executed " \
				<< this->getName() << RESET << std::endl;
		}
	}
}

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *f )
{
	std::cout << "___SHRUBBERY FORM " << f->getName() << " INFORMATION___\n"
		<< "|- NAME: " << f->getName() << "\n"
		<< "|- SIGNED: " << f->getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << "\n"
		<< "|- TARGET: " << f->getTarget() << std::endl;
	return ( o );		
}

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm &f )
{
	std::cout << "___SHRUBBERY FORM " << f.getName() << " INFORMATION___\n"
		<< "|- NAME: " << f.getName() << "\n"
		<< "|- SIGNED: " << f.getSigned() << "\n"
		<< "|- GRADE TO SIGN: " << f.getGradeToSign() << "\n"
		<< "|- GRADE TO EXECUTE: " << f.getGradeToExecute() << "\n"
		<< "|- TARGET: " << f.getTarget() << std::endl;
	return ( o );		
}
