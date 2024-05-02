#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

bool is_all_alpha(const std::string &str)
{
	if (str.empty())
		return false;
	for (int i = 0; i < str.length(); ++i)
		if (!std::isalpha(str[i]))
			return false;
	return true;
}

Contact createContact()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	while (true)
	{
    	std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, firstName))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (is_all_alpha(firstName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

    while (true)
	{
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, lastName))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (is_all_alpha(lastName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

	while (true)
	{
    	std::cout << "Enter Nick Name: ";
		if (!std::getline(std::cin, nickName))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (is_all_alpha(nickName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, phoneNumber))
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << "Error, empty line. Try again" << std::endl;
		}
		else
			break ;
	}

	while (true)
	{
    	std::cout << "Enter Darkest Secret: ";
    	if (!std::getline(std::cin, darkestSecret))
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << "Error, empty line. Try again" << std::endl;
		}
		else
			break ;
	}

	return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

void searchContacts(const PhoneBook& phoneBook)
{
    phoneBook.displayContacts();

    std::cout << "Enter the index of the contact to display: ";
    int index;
    while (!(std::cin >> index))
	{
        std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		clearerr(stdin);
		if (std::cin.eof())
			std::cout << std::endl;
        std::cout << "Invalid input. Enter the index of the contact to display: ";
    }
    std::cin.ignore();
    try
	{
        Contact contact = phoneBook.getContact(index);
        contact.display();
    }
	catch (const std::out_of_range &e)
	{
        std::cout << e.what() << std::endl;
	}
}

int main()
{
    PhoneBook phoneBook;

    while (true)
	{
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        
		if (!std::getline(std::cin, command))
		{
			std::cin.clear();
			clearerr(stdin);
		}
        if (command == "ADD")
            phoneBook.addContact(createContact());
        else if (command == "SEARCH")
            searchContacts(phoneBook);
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}
