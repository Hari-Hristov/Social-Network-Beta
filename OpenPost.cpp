#pragma once
#include "OpenPost.h"
#include "Util.h"

void OpenPost::execute(Post*& currentPost, Topic*& currentTopic, MyString& mode, const Vector<MyString>& input)
{
	size_t size = input.getSize();

	if (size == 1)
		throw std::length_error("Command [p_open] requires id or title.");

	if (size == 2 && isPositiveNumber(input[1]))
	{
		unsigned postId = toUnsigned(input[1]);
		bool found = false;

		for (size_t i = 0; i < currentTopic->posts.getSize(); i++)
		{
			if (postId == currentTopic->posts[i].getId())
			{
				found = true;
				mode = "post";
				currentPost = &currentTopic->posts[i];
				break;
			}
		}

		if (!found)
			throw std::invalid_argument("There is no post found with this id.");

		std::cout << "Successfully opened the post: " << currentPost->getTitle() << std::endl;
	}
	else
	{
		MyString postTitle = "";
		addText(postTitle, input, size);

		bool foundTopic = false;

		for (size_t i = 0; i < currentTopic->posts.getSize(); i++)
		{
			if (currentTopic->posts[i].getTitle() == postTitle)
			{
				foundTopic = true;
				currentPost = &currentTopic->posts[i];
				mode = "post";
				break;
			}
		}

		if (!foundTopic)
			throw std::invalid_argument("There is no post with this title in the current topic.");

		std::cout << "Successfully opened post: " << currentPost->getTitle() << std::endl;
	}
}
OpenPost& OpenPost::getInstance()
{
	static OpenPost openPost;
	return openPost;
}