#pragma once
#include "../Topic.h"
#include "../User.h"

class GeneralNavigation
{
	public:
		virtual void execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser) = 0;
		virtual ~GeneralNavigation() = default;
};