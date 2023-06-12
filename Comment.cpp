#include "Comment.h"

Comment::Comment(const MyString& authorName, const MyString& text, const unsigned id)
	:authorName(authorName), text(text), id(id)
{}

void Comment::print()
{
	std::cout << "User name is: " << authorName << std::endl
		<< "Comments writes: " << text << std::endl
		<< "With id: " << id << std::endl;
}

void Comment::addPoint()
{
	points++;
}

void Comment::removePoint()
{
	points--;
}

int Comment::getPoints() const
{
	return points;
}

unsigned Comment::getId() const
{
	return id;
}

void addUserIdToVoted(const unsigned userId, Vector<unsigned>& v)
{
	v.pushBack(userId);
}

void removeUserIdFromVoted(const unsigned userId, Vector<unsigned>& v)
{
	size_t index = 0;
	for (size_t i = 0; i < v.getSize(); i++)
	{
		if (userId == v[i])
		{
			index = i;
			break;
		}
	}
	v.popAt(index);
}


bool hasBeenVotedBy(const unsigned userId, Vector<unsigned>& v)
{
	for (size_t i = 0; i < v.getSize(); i++)
	{
		if (v[i] == userId)
			return true;
	}

	return false;
}


bool Comment::hasBeenLikedBy(unsigned userId)
{
	return hasBeenVotedBy(userId, likedByIds);
}
void Comment::addUserIdToLiked(unsigned userId)
{
	addUserIdToVoted(userId, likedByIds);
	addPoint();
}
void Comment::removeUserIdFromLiked(unsigned userId)
{
	removeUserIdFromVoted(userId, likedByIds);
	removePoint();
}

bool Comment::hasBeenDislikedBy(unsigned userId)
{
	return hasBeenVotedBy(userId, dislikedByIds);
}
void Comment::addUserIdToDisliked(unsigned userId)
{
	addUserIdToVoted(userId, dislikedByIds);
	addPoint();
}
void Comment::removeUserIdFromDisliked(unsigned userId)
{
	removeUserIdFromVoted(userId, dislikedByIds);
	removePoint();
}
