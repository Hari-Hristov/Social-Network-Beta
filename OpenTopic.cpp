#pragma once
#include "OpenTopic.h"
#include "Util.h"

void OpenTopic::execute(Vector<Topic>& topics, Topic*& currentTopic, MyString& mode, const Vector<MyString>& input)
{
	size_t size = input.getSize();

	if (size == 1)
		throw std::invalid_argument("Please enter a title of the topic you want to open.");

	else if (size == 2 && isPositiveNumber(input[1]))
	{
		unsigned searchedId = toUnsigned(input[1]);
		bool found = false;

		for (size_t i = 0; i < topics.getSize(); i++)
		{
			if (topics[i].getId() == searchedId)
			{
				currentTopic = &topics[i];
				found = true;
				mode = "topic";
				break;
			}
		}

		if (!found)
			throw std::out_of_range("There is no topic found with this id.");
		
		std::cout << "Successfully opened the topic: " << currentTopic->getTitle() << std::endl;

	}
	else
	{
		MyString title = "";
		addText(title, input, size);

		bool found = false;
		for (size_t i = 0; i < topics.getSize(); i++)
		{
			if (topics[i].getTitle() == title)
			{
				currentTopic = &topics[i];
				found = true;
				mode = "topic";
				break;
			}
		}

		if (!found)
			throw std::out_of_range("There is no topic found with this title.");

		std::cout << "Successfully opened the topic: " << currentTopic->getTitle() << std::endl;
	}
}

OpenTopic& OpenTopic::getInstance()
{
	static OpenTopic openTopic;
	return openTopic;
}