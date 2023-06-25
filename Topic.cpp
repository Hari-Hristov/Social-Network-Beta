#include "Topic.h"
#include "Util.h"

unsigned Topic::idCounter = 0;

Topic::Topic(const MyString& title, const MyString& creatorName, const MyString& description)
	: title(title), authorName(creatorName), description(description)
{
	id = idCounter++;
}

void Topic::setCounter(size_t n)
{
	idCounter = n;
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
		std::cout << "\t> " << "Title: " << posts[i].getTitle()
				  << " with id: " << posts[i].getId() << std:: endl;
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

void Topic::saveToFile(std::ofstream& ofs)
{
	// static idCounter - dont forget to add later
	title.saveToFile(ofs);
	authorName.saveToFile(ofs);
	description.saveToFile(ofs);
	ofs.write((const char*)&id, sizeof(id));
	ofs.write((const char*)&postId, sizeof(postId));
	
	size_t postsSize = posts.getSize();
	ofs.write((const char*)&postsSize, sizeof(postsSize));
	for (size_t i = 0; i < postsSize; i++)
	{
		posts[i].saveToFile(ofs);
	}
}

void Topic::loadFromFile(std::ifstream& ifs)
{
	title.loadFromFile(ifs);
	authorName.loadFromFile(ifs);
	description.loadFromFile(ifs);
	ifs.read((char*)&id, sizeof(id));
	ifs.read((char*)&postId, sizeof(postId));

	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		Post postToAdd;
		postToAdd.loadFromFile(ifs);
		posts.pushBack(postToAdd);
	}
}

