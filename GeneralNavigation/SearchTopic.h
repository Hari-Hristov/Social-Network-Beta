#pragma once
#include "GeneralNavigation.h"

class SearchTopic : public GeneralNavigation
{
	public:
		void execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser) override;
};