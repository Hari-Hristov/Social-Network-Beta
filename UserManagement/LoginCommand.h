#pragma once
#include "UserCommand.h"

class LoginCommand : public UserCommand
{
	public:

		virtual void execute(User*& currentUser, Vector<User>& users, const Vector<MyString>& input) override;
};