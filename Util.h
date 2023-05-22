#pragma once
#include "MyString.h"
#include "Vector.hpp"

namespace commandVariables
{
	const int MODES_COUNT = 3;
	const int TEXT_COMMANDS = 1;
	const int GENERAL_COMMANDS = 2;
	const int TOPIC_COMMANDS = 4;
	const int POST_COMMNADS = 6;

	static const MyString MODES[MODES_COUNT] =
	{
		"general", "topic", "post"
	};

	static const MyString TEXT_FUNCS[TEXT_COMMANDS] =
	{
		"search"
	};

	static const MyString GENERAL_FUNCS[GENERAL_COMMANDS] =
	{
		"open", "about"
	};
	static const MyString TOPIC_FUNCS[TOPIC_COMMANDS] = {
		"post", "p_open", "quit"
	};
	static const MyString POST_FUNCS[POST_COMMNADS] = {
		"comment", "comments", "reply", "upvote", "downvote", "p_close"
	};
}
bool isPositiveNumber(const MyString& str);
bool contains(const MyString* arr, const int size, const MyString el);
const Vector<MyString> split(const MyString& input, const char separator);
void addText(MyString& str, Vector<MyString>& vec, size_t size);