#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact(const Contact &new_contact)
{
	if (count < 8)
		contacts[count++] = new_contact;
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = new_contact;
	}
}

void PhoneBook::displayContacts() const
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < count; ++i)
	{
		int j = 0;
        std::cout << "|" << "         " << i << "|";
		
		j = contacts[i].getFirst_name().length();
		if (j > 10)
			std::cout << contacts[i].getFirst_name().substr(0, 9) + "." << "|";
		else
		{
			while (j++ < 10)
				std::cout << " ";
			std::cout << contacts[i].getFirst_name() << "|";
		}
        
		j = contacts[i].getLast_name().length();
		if (j > 10)
			std::cout << contacts[i].getLast_name().substr(0, 9) + "." << "|";
		else
		{
			while (j++ < 10)
				std::cout << " ";
			std::cout << contacts[i].getLast_name() << "|";
		}

		j = contacts[i].getNickname().length();
		if (j > 10)
			std::cout << contacts[i].getNickname().substr(0, 9) + "." << "|";
		else
		{
			while (j++ < 10)
				std::cout << " ";
			std::cout << contacts[i].getNickname() << "|" << std::endl;
		}
	}
}

Contact PhoneBook::getContact(int index) const
{
	if (index >= 0 && index < count)
		return contacts[index];
	else
		throw std::out_of_range("Index incorrect.");
}
