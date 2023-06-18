#pragma once
#include <fstream>
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

	void saveVectorOfUnsignedToFile(std::ofstream& ofs, const Vector<unsigned>& vector);
	void loadVectorOfUnsignedFromFile(std::ifstream& ifs, Vector<unsigned>& vector);

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

		void saveToFile(std::ofstream& ofs);
		void loadFromFile(std::ifstream& ifs);

		void print();
};

