#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137, "<target>")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called" <<  std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c) : AForm(c)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
	std::cout << "ShrubberyCreationForm copy assignement called" << std::endl;
	if (this != &c)
		AForm::operator=(c);
	return *this;
}

void ShrubberyCreationForm::task() const
{
	std::string 	filename = getTarget() + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file)
	{
		std::cerr << "Error: Could not open the file." << std::endl;
		return;
	}

	file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";

	file.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}

