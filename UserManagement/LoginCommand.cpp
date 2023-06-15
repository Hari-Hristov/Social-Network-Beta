#pragma once
#include "LoginCommand.h"

void LoginCommand::execute(User*& currentUser, Vector<User>& users, const Vector<MyString>& input)
{
	if (users.getSize() == 0)
		throw std::length_error("There are currently no created profiles to log into.");

	if (currentUser)
		throw std::invalid_argument("There is already a logged in user. Please logout first to log into another profile.");

	MyString firstName = "";
	std::cout << "Enter your first name: ";
	readWord(firstName);

	MyString lastName = "";
	std::cout << "Enter your last name: ";
	readWord(lastName);

	MyString password = "";
	std::cout << "Enter your password: ";
	readWord(password);

	User newUser = User(firstName, lastName, password);

	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (users[i] == newUser)
			currentUser = &users[i];
	}

	if (!currentUser)
		std::cout << "Login was not successfull. There is no such user." << std::endl;
	else
		std::cout << "Login was successfull." << std::endl;
}