#pragma once
#include "SearchTopic.h"
#include "../Util.h"

void SearchTopic::execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser)
{
	size_t size = input.getSize();

	if (size == 1)
	{
		throw std::invalid_argument("Please enter a text to search.");
	}
	MyString textToSearch = "";
	addText(textToSearch, input, size);

	Vector<Topic> result;
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].containsTextInTitle(textToSearch))
			result.pushBack(topics[i]);
	}

	size_t resultSize = result.getSize();

	if (resultSize == 0)
	{
		std::cout << "There are no matches found." << std::endl;
	}
	else
	{
		for (size_t i = 0; i < resultSize; i++)
		{
			result[i].print();
		}
	}
}
