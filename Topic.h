#pragma once
#include "Post.h"

class Topic
{
	static unsigned idCounter;
	MyString title = "";
	MyString creatorName = "";
	MyString description = "";
	unsigned id = 0;
	Vector<Post> posts;

	public:
		Topic() = default;
		Topic(const MyString& title, const MyString& creatorName, const MyString &description); //tuka po & li tr da sa

		void post(Post& post);
		void list();
		bool containsTextInTitle(const MyString& text);
		void print();

		MyString getTitle() const; //po kopie li tr da e
		unsigned getId() const;
};

