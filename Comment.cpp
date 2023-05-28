#include "Comment.h"

int Comment::getScore() const
{
	return upvotes - downvotes;
}

Comment::Comment(const MyString& authorName, const MyString& text, const unsigned id)
	:authorName(authorName), text(text), id(id)
{
	//id
}

void Comment::print()
{
	std::cout << "User name is: " << authorName << std::endl
			  << "Comments writes: " << text << std::endl
			  << "With id: " << id << std::endl;
}

