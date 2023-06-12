#pragma once
#include "MyString.h"

class User
{
	static unsigned idCounter;

	MyString firstName;
	MyString lastName;
	MyString password;
	unsigned id = 0;
	int points = 0;

	public:
		User() = default;
		User(const MyString& firstName, const MyString& lastName, const MyString& password);

		const MyString& getFirstName() const;
		const MyString& getLastName() const;
		int getPoints() const;
		unsigned getId() const;
		void whoami() const;

		bool verifyPassword(const MyString& pass) const;
		
		void addPoint();
		void removePoint();
		void givePoints(int amount);

		bool operator==(const User& user);
};
