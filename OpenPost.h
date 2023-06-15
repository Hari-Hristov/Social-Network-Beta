#pragma once
#include "Topic.h"

class OpenPost
{
	OpenPost() = default;
	OpenPost(const OpenPost&) = delete;
	OpenPost& operator=(const OpenPost&) = delete;

public:
	void execute(Post*& currentPost, Topic*& currentTopic, MyString& mode, const Vector<MyString>& input);
	static OpenPost& getInstance();
};