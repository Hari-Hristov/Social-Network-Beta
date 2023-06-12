#pragma once
#include "Vector.hpp"
#include "MyString.h"

class Comment
{
	MyString authorName = "";
	MyString text = "";
	unsigned id = 0;
	int points = 0;

	Vector<unsigned> votedByIds;
	Vector<unsigned> likedByIds;
	Vector<unsigned> dislikedByIds;

	void addPoint();
	void removePoint();
	public:
		Comment() = default;
		Comment(const MyString& authorName, const MyString& text, const unsigned id);
		
		int getPoints() const;
		unsigned getId() const;

		bool hasBeenLikedBy(unsigned userId);
		void addUserIdToLiked(unsigned userId);
		void removeUserIdFromLiked(unsigned userId);

		bool hasBeenDislikedBy(unsigned userId);
		void addUserIdToDisliked(unsigned userId);
		void removeUserIdFromDisliked(unsigned userId);

		void print();
};

