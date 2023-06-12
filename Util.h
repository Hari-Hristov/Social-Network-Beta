#pragma once
#include "MyString.h"
#include "Vector.hpp"

namespace commandVariables
{
	const unsigned MODES_COUNT = 3;
	const unsigned USER_COMMANDS = 4;
	const unsigned TEXT_COMMANDS = 1;
	const unsigned GENERAL_COMMANDS = 3;
	const unsigned TOPIC_COMMANDS = 4;
	const unsigned POST_COMMNADS = 6;

	static const MyString MODES[MODES_COUNT] =
	{
		"general", "topic", "post"
	};

	static const MyString USER_FUNCS[USER_COMMANDS] =
	{
		"login", "register", "whoami", "logout"
	};

	static const MyString TEXT_FUNCS[TEXT_COMMANDS] =
	{
		"search"
	};

	static const MyString GENERAL_FUNCS[GENERAL_COMMANDS] =
	{
		"open", "about", "create"
	};
	static const MyString TOPIC_FUNCS[TOPIC_COMMANDS] = {
		"post", "p_open", "quit"
	};

	static const MyString POST_FUNCS[POST_COMMNADS] = {
		"comment", "comments", "reply", "upvote", "downvote", "p_close"
	};
}
bool isPositiveNumber(const MyString& str);
bool contains(const MyString* arr, const unsigned size, const MyString el);
const Vector<MyString> split(const MyString& input, const char separator);
void addText(MyString& str, Vector<MyString>& vec, size_t size);
void readWord(MyString& word);
