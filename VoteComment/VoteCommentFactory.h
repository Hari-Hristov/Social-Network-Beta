#pragma once
#include "VoteComment.h"

class VoteCommentFactory
{
	VoteCommentFactory() = default;
	VoteCommentFactory(const VoteCommentFactory&) = delete;
	VoteCommentFactory& operator=(const VoteCommentFactory&) = delete;

public:
	VoteComment* getCommand(const MyString& command) const;
	static VoteCommentFactory& getInstance();
};