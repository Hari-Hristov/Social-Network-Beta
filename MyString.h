#pragma once
#include <iostream>
#include <fstream>

class MyString
{
	char* _data;
	size_t _length;

	void copyFrom(const MyString& data);
	void free();

	explicit MyString(size_t capacity);
public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	size_t length() const;
	MyString& operator+=(const MyString& other);
	MyString& operator+=(const char other);

	MyString substr(size_t begin, size_t howMany) const;
	bool contains(const MyString& other);
	unsigned toUnsigned();
	void clear();

	char& operator[](size_t index);
	char operator[](size_t index) const;

	const char* c_str() const;

	void saveToFile(std::ofstream& ofs) const;
	void loadFromFile(std::ifstream& ifs);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);