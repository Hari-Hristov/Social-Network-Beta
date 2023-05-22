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
		Post(const MyString& title, const MyString& desc);
		
		MyString getTitle() const; //tuka ms s & li tr da e?
		MyString getDesc() const;
		unsigned getId() const;
		void comment(Comment& comment);

		void print();
};

bool operator==(const Post& lhs, const Post& rhs);

