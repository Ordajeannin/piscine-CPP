#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
	Contact contacts[8];
	int count;

public:
	PhoneBook();
	void addContact(const Contact &new_contact);
	void displayContacts() const;
	Contact getContact(int index) const;
};

#endif
