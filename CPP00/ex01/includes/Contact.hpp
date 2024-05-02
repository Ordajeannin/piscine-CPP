#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	Contact(const std::string &first_name, const std::string &last_name,
			const std::string &nickname, const std::string &phone_number,
			const std::string &darkest_secret);

	std::string getFirst_name() const;
	std::string getLast_name() const;
	std::string getNickname() const;
	std::string getPhone_number() const;
	std::string getDarkest_secret() const;

	void display() const;
};

#endif
