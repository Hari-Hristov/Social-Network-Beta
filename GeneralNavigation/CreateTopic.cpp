#pragma once
#include "CreateTopic.h"
#include "../Util.h"

void CreateTopic::execute(Vector<Topic>& topics, const Vector<MyString>& input, User*& currentUser)
{
	std::cout << "Enter you topic's title: ";
	MyString title;
	readWord(title);

	std::cout << "Enter your topic's desc: ";
	MyString desc;
	readWord(desc);

	topics.pushBack(Topic(title, currentUser->getFirstName(), desc));
	std::cout << "Successfully created the topic." << std::endl;
}
