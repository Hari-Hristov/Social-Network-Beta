#pragma once
#include "Vector.hpp"
#include "MyString.h"

class Comment
{
	MyString authorName = "";
	MyString text = "";
	unsigned id = 0;
	int upvotes = 0;
	int downvotes = 0;

	public:
		Comment() = default;
		Comment(const MyString& authorName, const MyString& text, const unsigned id);
		

		int getScore() const; //done
		void print();
};

