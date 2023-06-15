#pragma once
#include "../User.h"
#include "../Vector.hpp"
#include "../Util.h"

class UserCommand
{
	public:
		virtual void execute(User*& currentUser, Vector<User>& users, const Vector<MyString>& input) = 0;

		virtual ~UserCommand() = default;
};