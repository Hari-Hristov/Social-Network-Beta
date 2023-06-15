#pragma once
#include "GeneralNavigation.h"

class AboutTopic : public GeneralNavigation
{
	public:
		void execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser) override;
};