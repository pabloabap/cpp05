//CABECERA

#include "form_tests.hpp"


/** Checking all Form functions work as expected
 * EXPECTED: Functions match attributes values. Exception trying to sign f2.
 */

void testFormFunctions( void )
{
	std::cout << PINK << "*** testFormFunctions called *** " << RESET << std::endl;
	try
	{
		Form		f;
		Form		f2("FORM2", 10, 1);
		Form		f3(f2);
		Bureaucrat	b;
		
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		
		std::cout << "GET NAME - " << f.getName() << "\n"
			<< "GET SIGNED - " << f.getSigned() << "\n"
			<< "GET G2SIGN - " << f.getGradeToSign() << "\n"
			<< "GET G2EXEC - " << f.getGradeToExecute() << std::endl;
		f.beSigned( b );
		std::cout << "GET SIGNED - " <<f.getSigned() << std::endl;
		std::cout << f2 << std::endl;
		f2 = f;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		f2.beSigned( b );
	}
	catch ( const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
}

/** Default Bureaucrat and form in range and signs higher than Bureaucrat grade.
 * EXPECTED: Excepntion Form::GradeToLow
*/
void testRangeFormDefBur( void )
{
	Bureaucrat	*a = new Bureaucrat( );
	Form		*f = new Form("Confidential", 10, 5);
	
	std::cout << PINK << "*** testRangeFormDefBur called *** " << RESET << std::endl;
	try
	{
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Sign grande higher than bureaucrat grade.
 * EXPECTED: Too low exception to sign.
*/
void testHighSign( void )
{
	Bureaucrat	*a = new Bureaucrat( );
	Form		*f = new Form("Confidential", 10, 150);
	
	std::cout << PINK << "*** testHighSign called *** " << RESET << std::endl;
	try
	{
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Execute grande higher than bureaucrat grade.
 * EXPECTED: Waring on sign seccond try.
*/
void testHighExec( void )
{
	Bureaucrat	*a = new Bureaucrat( );
	Form		*f = new Form("Confidential", 150, 10);
	
	std::cout << PINK << "*** testHighExec called *** " << RESET << std::endl;
	try
	{
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Sign grade out of range higher.
 * EXPECTED: Too hihg sign form exception.
*/
void	testSingTooHigher( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testSingTooHigher called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat();
		f = new Form("OUT", 0, 150);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Sign grade out of range lower.
 * EXPECTED: Too low sign form exception.
*/
void	testSingTooLower( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testSingTooLow called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat();
		f = new Form("OUT", 160, 150);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Exec grade out of range higher.
 * EXPECTED: Too hihg exec form exception.
*/
void	testExecTooHigher( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testExecTooHigher called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat();
		f = new Form("OUT", 150, 0);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

/** Exec grade out of range lower.
 * EXPECTED: Too low exec form exception.
*/
void	testExecTooLower( void )
{
	Bureaucrat	*a = NULL;
	Form		*f = NULL;

	std::cout << PINK << "*** testSingTooLow called *** " << RESET << std::endl;
	try
	{
		a = new Bureaucrat();
		f = new Form("OUT", 150, 160);
	
		std::cout << "-----------------------------\n"
			<< "INITIAL BUREAUCRAT VALUES: " << a << f 
			<< "-----------------------------\n"
			<< "Sign form " << std::endl;
		a->signForm( *f );
		std::cout << f << "Try to sign again" << std::endl;
		a->signForm( *f );
		
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}	
	if ( a )
		delete ( a );
	if ( f )
		delete ( f );
}

