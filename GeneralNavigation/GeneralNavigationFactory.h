#pragma once
#include "GeneralNavigation.h"

class GeneralNavigationFactory
{
	GeneralNavigationFactory() = default;
	GeneralNavigationFactory(const GeneralNavigationFactory&) = delete;
	GeneralNavigationFactory& operator=(const GeneralNavigationFactory&) = delete;

public:
	GeneralNavigation* getCommand(const MyString& command) const;
	static GeneralNavigationFactory& getInstance();
};