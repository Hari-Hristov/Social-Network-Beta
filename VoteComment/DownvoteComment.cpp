#pragma once
#include "DownvoteComment.h"
#include "../Util.h"

void DownvoteComment::execute(User*& currentUser, Post*& currentPost, Comment*& currentComment, const Vector<MyString>& input)
{
	size_t size = input.getSize();

	if (size != 2)
		throw std::invalid_argument("Upvote command takes only id.");

	if (!isPositiveNumber(input[1]))
		throw std::invalid_argument("Id is not a positive number");

	unsigned idToVote = toUnsigned(input[1]);

	try
	{
		currentComment = &currentPost->getCommentById(idToVote);
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl;
		return;
	}
	unsigned userId = currentUser->getId();

	if (currentComment->hasBeenLikedBy(userId))
	{
		currentComment->removeUserIdFromLiked(userId);
		currentUser->removePoint();
	}

	if (currentComment->hasBeenDislikedBy(userId))
	{
		currentComment->removeUserIdFromDisliked(userId);
		currentUser->removePoint();
	}
	else
	{
		currentComment->addUserIdToDisliked(userId);
		currentUser->addPoint();
	}
}