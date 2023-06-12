#pragma once
#include "Comment.h"

class Post
{
	MyString title = "";
	MyString desc = "";
	unsigned id = 0;
	unsigned commentId = 0;
	Vector<Comment> comments;

	public:
		Post() = default;
		Post(const MyString& title, const MyString& desc, const unsigned id);
		
		const MyString& getTitle() const;
		const MyString& getDesc() const;
		unsigned getId() const;
		void comment(const MyString& authorName, const MyString& text);
		void showComments();

		Comment& getCommentById(const unsigned commentId);
		void print();
};

bool operator==(const Post& lhs, const Post& rhs);

