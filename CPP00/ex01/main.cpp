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

Contact createContact() {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	while (true)
	{
    	std::cout << "Enter First Name: ";
    	std::getline(std::cin, firstName);
		if (is_all_alpha(firstName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

    while (true)
	{
		std::cout << "Enter Last Name: ";
    	std::getline(std::cin, lastName);
		if (is_all_alpha(lastName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

	while (true)
	{
    	std::cout << "Enter Nick Name: ";
    	std::getline(std::cin, nickName);
		if (is_all_alpha(nickName))
			break;
		else
			std::cout << "Error: must contain only alphabetic characters. Try again" << std::endl;
	}

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

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
        std::getline(std::cin, command);

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

