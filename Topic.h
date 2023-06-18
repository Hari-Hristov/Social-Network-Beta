#pragma once
#include "Post.h"

class Topic
{
	static unsigned idCounter;
	MyString title = "";
	MyString authorName = "";
	MyString description = "";
	unsigned id = 0;
	unsigned postId = 0;

	bool containsPost(const Post& post);

	public:

		Topic() = default;
		Topic(const MyString& title, const MyString& authorName, const MyString &description); 

		const MyString& getTitle() const;
		unsigned getId() const;

		Vector<Post> posts;
		void post(const MyString& title, const MyString& desc);
		void list();
		bool containsTextInTitle(const MyString& text);
		
		void saveToFile(std::ofstream& ofs);
		void loadFromFile(std::ifstream& ifs);

		void print();
};

