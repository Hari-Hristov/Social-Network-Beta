#pragma once
#include "../Post.h"
#include "../User.h"

class VoteComment
{
	public:
		virtual void execute(User*& currentUser, Post*& currentPost, Comment*& currentComment, const Vector<MyString>& input) = 0;
		virtual ~VoteComment() = default;
};