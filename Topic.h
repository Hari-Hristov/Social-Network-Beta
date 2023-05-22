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

	bool containsPost(const Post& post);
	bool containsPost(Post&& post);

	public:
		Topic() = default;
		Topic(const MyString& title, const MyString& creatorName, const MyString &description); //tuka po & li tr da sa

		void post(const Post& post);
		void post(Post&& post);
		void list();
		bool containsTextInTitle(const MyString& text);
		void print();

		MyString getTitle() const; //po kopie li tr da e
		unsigned getId() const;
};

