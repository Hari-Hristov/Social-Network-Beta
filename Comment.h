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
		Comment(MyString authorName, MyString text);
		
		int getScore() const; //done
};

