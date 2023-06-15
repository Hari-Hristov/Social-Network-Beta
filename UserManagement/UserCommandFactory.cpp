#pragma once
#include "UserCommandFactory.h"
#include "UserCommand.h"
#include "LoginCommand.h"
#include "RegisterCommand.h"

UserCommandFactory& UserCommandFactory::getInstance()
{
	static UserCommandFactory factory;
	return factory;
}

UserCommand* UserCommandFactory::getCommand(const MyString& command) const
{
	if (command == "login")
	{
		return new LoginCommand();
	}
	else if (command == "register")
	{
		return new RegisterCommand();
	}

	return nullptr;
}
