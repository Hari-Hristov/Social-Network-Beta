#pragma once
#include "GeneralNavigationFactory.h"
#include "CreateTopic.h"
#include "AboutTopic.h"
#include "SearchTopic.h"

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
	else if (command == "search")
	{
		return new SearchTopic();
	}
	else if (command == "about")
	{
		return new AboutTopic();
	}

	return nullptr;
}
