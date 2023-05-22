#include "Post.h"


Post::Post(const MyString& title, const MyString& desc)
	:title(title), desc(desc)
{
	//id
};

void Post::comment(Comment& comment)
{
	comments.pushBack(comment);
};

MyString Post::getTitle() const
{
	return this->title;
};

MyString Post::getDesc() const
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

void Post::print()
{
	std::cout << "Title is: " << title << std::endl
			  << "Description is: " << desc << std::endl
			  << "With id: " << id << std::endl;
}
