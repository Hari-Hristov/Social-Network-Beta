#pragma once
#include "Comment.h"

class Post
{
	MyString title = "";
	MyString desc = "";
	unsigned id = 0;
	Vector<Comment> comments;

	public:
		Post() = default;
		Post(MyString title, MyString desc);
		MyString getTitle() const; //tuka ms s & li tr da e?
		unsigned getId() const;
		void comment(Comment& comment);
};

