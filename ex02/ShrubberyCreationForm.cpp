//CABECERA

#include "ShrubberyCreationForm.hpp"

ShrubberryCreationForm::ShrubberyCreationForm( void ): \
	AForm( "Shurberry", 145, 137 ), _target("target"){}

ShrubberryCreationForm::ShrubberyCreationForm( std::string const &target )
	AForm( "Shurberry", 145, 137 ), _target(target){}

ShrubberryCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &f ): \
	AForm( f.getName(), f.getGradeToSign(), f.getGradeToExecute() ), _target(f._target){}

ShrubberryCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &f )
{
	if ( this != &f)	
	{
		this->_target = f._target;
		AForm::operator=(f);
	}
	return ( *this );
}

std::string const	&Shurberry::getTarget( void ) const
{
	return ( this->_target );
}

void			Shurberry::execute( Bureaucrat const &executor )
{
	std::ostringstream	executeGrade;
	std::ostringstream	bureauctratGrade;
	std::string		msg;

	executeGrade << this->getGradeToExecute();	
	bureauctratGrade << executor.getGrade();	
	if ( false == this->getSigned() )
		std::cout << CYAN << this->getName() << " not signed. Sign "
			<< "the documment before execute it." << RESET << std::end;
	else if ( executor.getGrade() > this->getGradeToExecute() )
	{
		msg = "Grade too low: Bureaucrat grade " + bureauctratGrade.str() \
			+ " is lower than grade required to execute " \
			+ this->getName() + "(" + executeGrade.str() + ")"
		throw AForm::GradeTooLowException( msg );
	}
	else
	{
		std::ofstream outfile((this->_target.append("_shrubbery")).c_str());
		if (outfile.fail())
			std::cout << "Unable to create new file" << std::endl;
		else
		{
			outfile << "       ### " << std::endl;
			outfile << "      #o### " << std::endl;
			outfile << "    #####o### " << std::endl;
			outfile << "   #o#\\#|#/### " << std::endl;
			outfile << "    ###\\|/#o# " << std::endl;
			outfile << "     # }|{  # " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile << "       }|{ " << std::endl;
			outfile.close();
		}
			
	}
}

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *f )
{
	std::cout << "___FORM " << f->getName() << " INFORMATION___\n" \
		<< "|- NAME: " << f->getName() << "\n" \
		<< "|- SIGNED: " << f->getSigned() << "\n" \
		<< "|- GRADE TO SIGN: " << f->getGradeToSign() << "\n" \
		<< "|- GRADE TO EXECUTE: " << f->getGradeToExecute() << std::endl;
		<< "|- TARGET: " << f->getTaret() << std::endl;
	return ( o );		
}

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm &f )
{
	std::cout << "___FORM " << f.getName() << " INFORMATION___\n" \
		<< "|- NAME: " << f.getName() << "\n" \
		<< "|- SIGNED: " << f.getSigned() << "\n" \
		<< "|- GRADE TO SIGN: " << f.getGradeToSign() << "\n" \
		<< "|- GRADE TO EXECUTE: " << f.getGradeToExecute() << std::endl;
		<< "|- TARGET: " << f->getTaret() << std::endl;
	return ( o );		
}
