#pragma once
#include "VoteCommentFactory.h"
#include "UpvoteComment.h"
#include "DownvoteComment.h"

VoteCommentFactory& VoteCommentFactory::getInstance()
{
	static VoteCommentFactory factory;
	return factory;
}

VoteComment* VoteCommentFactory::getCommand(const MyString& command) const
{
	if (command == "upvote")
	{
		return new UpvoteComment();
	}
	else if(command == "downvote")
	{
		return new DownvoteComment();
	}
	else
	{
		return nullptr;
	}
}