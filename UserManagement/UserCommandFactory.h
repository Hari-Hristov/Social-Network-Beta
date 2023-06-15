#pragma once
#include "UserCommand.h"

class UserCommandFactory
{
	UserCommandFactory() = default;
	UserCommandFactory(const UserCommandFactory&) = delete;
	UserCommandFactory& operator=(const UserCommandFactory&) = delete;

public:
	UserCommand* getCommand(const MyString& command) const;
	static UserCommandFactory& getInstance();
};