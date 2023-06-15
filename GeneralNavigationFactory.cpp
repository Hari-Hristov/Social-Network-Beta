#pragma once
#include "GeneralNavigationFactory.h"
#include ""

GeneralNavigationFactory& GeneralNavigationFactory::getInstance()
{
	static GeneralNavigationFactory factory;
	return factory;
}

GeneralNavigation* GeneralNavigationFactory::getCommand(const MyString& command) const
{
	if (command == "create")
	{
		return new CreateTopic();
	}
	else if (command == "register")
	{
		return new RegisterCommand();
	}

	return nullptr;
}
