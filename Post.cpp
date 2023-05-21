#include "Post.h"

Post::Post(MyString title, MyString desc)
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

unsigned Post::getId() const
{
	return this->id;
};