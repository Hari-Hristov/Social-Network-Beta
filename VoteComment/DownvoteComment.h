#pragma once
#include "VoteComment.h"

class DownvoteComment : public VoteComment
{
	public:
		virtual void execute(User*& currentUser, Post*& currentPost, Comment*& currentComment, const Vector<MyString>& input) override;
};