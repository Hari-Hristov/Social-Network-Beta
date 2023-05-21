#include "Comment.h"

int Comment::getScore() const
{
	return upvotes - downvotes;
}

Comment::Comment(MyString authorName, MyString text)
	:authorName(authorName), text(text)
{
	//id
}

