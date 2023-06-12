#include "Post.h"


Post::Post(const MyString& title, const MyString& desc, const unsigned id)
	:title(title), desc(desc), id(id)
{
};

void Post::comment(const MyString& authorName, const MyString& text)
{
	
	comments.pushBack(Comment(authorName, text, commentId++));
};

const MyString& Post::getTitle() const
{
	return this->title;
};

const MyString& Post::getDesc() const
{
	return desc;
}

unsigned Post::getId() const
{
	return this->id;
};

bool operator==(const Post& lhs, const Post& rhs)
{
	return lhs.getTitle() == rhs.getTitle() && lhs.getDesc() == rhs.getDesc(); //without id in order to prevent spam from different accs.
}

Comment& Post::getCommentById(const unsigned commentId)
{
	size_t commentsSize = comments.getSize();

	if (commentId >= commentsSize)
		throw std::invalid_argument("Id is not valid");

	for (size_t i = 0; i < commentsSize; i++)
	{
		if (comments[i].getId() == commentId)
			return comments[i];
	}
}

void Post::print()
{
	std::cout << "Title is: " << title << std::endl
			  << "Description is: " << desc << std::endl
			  << "With id: " << id << std::endl;
}

void Post::showComments()
{
	for (size_t i = 0; i < comments.getSize(); i++)
	{
		comments[i].print();
		std::cout << std::endl;
	}
}
