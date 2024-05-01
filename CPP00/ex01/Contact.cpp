#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

Contact::Contact(const std::string &first_name, const std::string &last_name,
				const std::string &nickname, const std::string &phone_number,
				const std::string &darkest_secret)
{
    this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::getFirst_name() const { return first_name; }
std::string Contact::getLast_name() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhone_number() const { return phone_number; }
std::string Contact::getDarkest_secret() const { return darkest_secret; }

void Contact::display() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
