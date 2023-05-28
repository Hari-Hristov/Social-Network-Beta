#include "Topic.h"

unsigned Topic::idCounter = 0;

Topic::Topic(const MyString& title, const MyString& creatorName, const MyString& description)
	: title(title), authorName(creatorName), description(description)
{
	id = idCounter++;
}

unsigned Topic::getId() const
{
	return id;
}

const MyString& Topic::getTitle() const
{
	return title;
}

//---------------------------
bool Topic::containsTextInTitle(const MyString& text)
{
	return title.contains(text);
}


void Topic::post(const MyString& title, const MyString& desc)
{
	posts.pushBack(Post(title, desc, postId++));
}

bool Topic::containsPost(const Post& post)
{
	for (size_t i = 0; i < posts.getSize(); i++)
	{
		if (posts[i] == post)
			return true;
	}

	return false;
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
		<< "Creator: " << authorName << std::endl
		<< "Description: " << description << std::endl
		<< "Id: " << id << std::endl << std::endl;
	//posts
	for (size_t i = 0; i < posts.getSize(); i++)
	{
		posts[i].print();
	}
}

