#pragma once
#include "VoteComment.h"

class UpvoteComment : public VoteComment
{
	public:
		virtual void execute(User*& currentUser, Post*& currentPost, Comment*& currentComment, const Vector<MyString>& input) override;
};