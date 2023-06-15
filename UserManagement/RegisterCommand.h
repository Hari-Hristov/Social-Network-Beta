#pragma once
#include "UserCommand.h"

class RegisterCommand : public UserCommand
{
	public:

		virtual void execute(User*& currentUser, Vector<User>& users, const Vector<MyString>& input) override;
};