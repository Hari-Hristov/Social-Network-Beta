#pragma once
#include "Topic.h"

class OpenTopic
{
	OpenTopic() = default;
	OpenTopic(const OpenTopic&) = delete;
	OpenTopic& operator=(const OpenTopic&) = delete;

public:
	void execute(Vector<Topic>& topics, Topic*& currentTopic, MyString& mode, const Vector<MyString>& input);
	static OpenTopic& getInstance();
};