#include "Topic.h"

unsigned Topic::idCounter = 0;

Topic::Topic(const MyString& title, const MyString& creatorName, const MyString& description)
	: title(title), creatorName(creatorName), description(description)
{
	id = idCounter++;
}

unsigned Topic::getId() const
{
	return id;
}

MyString Topic::getTitle() const
{
	return title;
}

//---------------------------
bool Topic::containsTextInTitle(const MyString& text)
{
	return title.contains(text);
}


void Topic::post(Post& post)
{
	posts.pushBack(post);
}

void Topic::list()
{
	for (int i = 0; i < posts.getSize(); i++)
	{
		std::cout << "\t> " << posts[i].getTitle() 
				  << " { " << posts[i].getId() << " }" << std:: endl;
	}
}

void Topic::print()
{
	std::cout << "Name: " << title << std::endl
		<< "Creator: " << creatorName << std::endl
		<< "Description: " << description << std::endl
		<< "Id: " << id << std::endl << std::endl;
	//posts
}

