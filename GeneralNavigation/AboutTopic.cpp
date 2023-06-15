#pragma once
#include "AboutTopic.h"
#include "../Util.h"

void AboutTopic::execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser)
{
	size_t size = input.getSize();
	if (size != 2 || !isPositiveNumber(input[1]))
		throw std::bad_cast();

	unsigned searchedId = toUnsigned(input[1]);
	bool found = false;

	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getId() == searchedId)
		{
			topics[i].print();
			found = true;
			break;
		}
	}

	if (!found)
		throw std::invalid_argument("Cannot show information on this topic because it does not exit.");
}
