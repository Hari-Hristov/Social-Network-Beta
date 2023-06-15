#pragma once
#include "RegisterCommand.h"

void RegisterCommand::execute(User*& currentUser, Vector<User>& users, const Vector<MyString>& input)
{
	if (currentUser)
		throw std::invalid_argument("There is already a logged in user.");

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
		if (users[i].getFirstName() == firstName && users[i].getLastName() == lastName)
		{
			std::cout << "There is already a user with these names." << std::endl;
			return;
		}
	}

	users.pushBack(newUser);
	currentUser = &users[users.getSize() - 1];
	std::cout << "Successfully registered!" << std::endl;
}

