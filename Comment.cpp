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

void Comment::reply(const MyString& reply)
{
	replies.pushBack(reply);
}

void Comment::showReplies() const
{
	size_t repliesSize = replies.getSize();
	for (size_t i = 0; i < repliesSize; i++)
	{
		std::cout << replies[i] << std::endl;
	}
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

void Comment::saveToFile(std::ofstream& ofs)
{
	authorName.saveToFile(ofs);
	text.saveToFile(ofs);
	ofs.write((const char*)&id, sizeof(id));
	ofs.write((const char*)&points, sizeof(points));

	// make the vectors from sharedPtrs of the wanted type because now i am saving bytes in the file that are empty and have no information in them
	saveVectorOfUnsignedToFile(ofs, likedByIds);
	saveVectorOfUnsignedToFile(ofs, dislikedByIds);

	size_t size = replies.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		replies[i].saveToFile(ofs);
	}
}

void Comment::saveVectorOfUnsignedToFile(std::ofstream& ofs, const Vector<unsigned>& vector)
{
	size_t size = vector.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		ofs.write((const char*)&vector[i], sizeof(vector[i]));
	}
}

void Comment::loadFromFile(std::ifstream& ifs)
{
	authorName.loadFromFile(ifs);
	text.loadFromFile(ifs);
	ifs.read((char*)&id, sizeof(id));
	ifs.read((char*)&points, sizeof(points));

	loadVectorOfUnsignedFromFile(ifs, likedByIds);
	loadVectorOfUnsignedFromFile(ifs, dislikedByIds);

	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		MyString toAdd;
		toAdd.loadFromFile(ifs);
		replies.pushBack(toAdd);
	}
}

void Comment::loadVectorOfUnsignedFromFile(std::ifstream& ifs, Vector<unsigned>& vector)
{
	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		unsigned toAdd = 0;
		ifs.read((char*)&toAdd, sizeof(toAdd));
		vector.pushBack(toAdd);
	}
}