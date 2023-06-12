#include "User.h"

unsigned User::idCounter = 0;

User::User(const MyString& firstName, const MyString& lastName, const MyString& password) 
	:firstName(firstName), lastName(lastName), password(password)
{
	id = idCounter++;
	points = 0;
}

const MyString& User::getFirstName() const
{
	return firstName;

}
const MyString& User::getLastName() const
{
	return lastName;
}

int User::getPoints() const
{
	return points;
}

unsigned User::getId() const
{
	return id;
}

void User::givePoints(int amount)
{
	points += amount;
}

bool User::verifyPassword(const MyString& pass) const
{
	return password == pass;
}

void User::whoami() const
{
	std::cout << firstName << ", with " << points << " points." << std::endl;
}

bool User::operator==(const User& user)
{
	return firstName == user.getFirstName() && lastName == user.getLastName() && user.verifyPassword(password);
}

void User::addPoint()
{
	points++;
}

void User::removePoint()
{
	points--;
}
