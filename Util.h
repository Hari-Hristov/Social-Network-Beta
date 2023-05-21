#pragma once
#include "MyString.h"
#include "Vector.hpp"

namespace commandVariables
{
	const int MODES_COUNT = 3;
	const int TEXT_COMMANDS = 1;
	const int GENERAL_COMMANDS = 1;
	const int TOPIC_COMMANDS = 5;
	const int POST_COMMNADS = 6;

	static const MyString MODES[MODES_COUNT] =
	{
		"general", "topic", "post"
	};

	static const MyString TEXT_FUNCS[TEXT_COMMANDS] =
	{
		"search"
	};

	static const MyString generalFuncs[GENERAL_COMMANDS] =
	{
		"open"
	};
	static const MyString topicFuncs[TOPIC_COMMANDS] = {
		"post", "about", "p_open", "quit"
	};
	static const MyString postFuncs[POST_COMMNADS] = {
		"comment", "comments", "reply", "upvote", "downvote", "p_close"
	};
}
bool isPositiveNumber(const MyString& str);
bool contains(const MyString* arr, const int size, const MyString el);
const Vector<MyString> split(const MyString& input, const char separator);
void addText(MyString& str, Vector<MyString>& vec, size_t size);