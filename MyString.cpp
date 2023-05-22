#include "MyString.h"
#include "Util.h"
#pragma warning (disable:4996)

MyString::MyString(size_t capacity)
{
	_length = capacity - 1;
	_data = new char[capacity];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs._length + rhs._length + 1);

	result[0] = '\0';
	strcat(result._data, lhs._data);
	strcat(result._data, rhs._data);

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[(_length += other._length) + 1];
	result[0] = '\0';
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;

	return *this;
}

MyString& MyString::operator+=(const char ch)
{
	
	char* result = new char[_length + 1 + 1];
	result[0] = '\0';
	strcat(result, _data);
	result[_length] = ch;
	result[_length + 1] = '\0';
	delete[] _data;
	_data = result;
	_length++;
	return *this;
}

MyString::MyString() : MyString(1)
{
	_data[0] = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	strcpy(_data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
	delete[] _data;
	_data = nullptr;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return _length;
}

void MyString::copyFrom(const MyString& other)
{
	_length = other._length;
	_data = new char[_length + 1];
	strcpy(_data, other._data);
}

MyString::MyString(MyString&& other) noexcept
{
	_data = other._data;
	other._data = nullptr;
	_length = other._length;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		_data = other._data;
		other._data = nullptr;
		_length = other._length;
	}
	return *this;
}

char& MyString::operator[](size_t index) //neconst dostup
{
	return _data[index];
}

char MyString::operator[](size_t index) const //const dostup
{
	return _data[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > _length)
		throw std::length_error("Error, Substr out of range");


	MyString res(howMany + 1);
	for (int i = 0; i < howMany; i++)
		res._data[i] = _data[begin + i];
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
	return _data;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; // is.getLine(buff, 1024);

	delete[] str._data;
	str._length = strlen(buff);
	str._data = new char[str._length + 1];
	strcpy(str._data, buff);
	return is;
}


bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

void MyString::clear()
{
	delete[] _data;
	_length = 0;
	_data = new char[_length + 1];
	_data[0] = '\0';
}

bool MyString::contains(const MyString& other)
{
	size_t n = this->length();
	size_t m = other.length();

	for (int i = 0; i <= n - m; ++i) {
		int j = 0;
		while (j < m && this->c_str()[i + j] == other[j]) {
			j++;
		}
		if (j == m) {
			return true;
		}
	}
	return false;
}

unsigned MyString::toUnsigned()
{
	if (!isPositiveNumber(*this))
		throw std::invalid_argument("String cannot be converted to a positive number.");

	unsigned result = 0;
	for (size_t i = 0; i < this->length(); i++)
	{
		result = 10 * result + (this->c_str()[i] - '0');
	}

	return result;
}
