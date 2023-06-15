#include "Util.h"


bool contains(const MyString* arr, const unsigned size, const MyString el)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == el)
			return true;
	}

	return false;
}

const Vector<MyString> split(const MyString& input, const char separator)
{
	Vector<MyString> res;
	MyString str = "";
	size_t len = input.length();

	if (input.length() == 0)
		return res;

	for (size_t i = 0; i <= len; i++)
	{
		if (input[i] == separator || i == len)
		{
			if (str.length() != 0)
			{ 
				res.pushBack(str);
				str.clear(); 
			}
			continue;
		}
		str += input[i];
	}
	return res;
}

bool isPositiveNumber(const MyString& str)
{
	size_t len = str.length();
	if (len == 0)
		return false;
	if (len > 0 && str[0] == '-')
		return false;

	for (size_t i = 0; i < len; i++)
	{
		if ('9' < str[i] || str[i] < '0')
			return false;
	}

	return true;
}

unsigned toUnsigned(const MyString& str)
{
	if (!isPositiveNumber(str))
		throw std::invalid_argument("String cannot be converted to a positive number.");

	unsigned result = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		result = 10 * result + (str.c_str()[i] - '0');
	}

	return result;
}

void addText(MyString& str, const Vector<MyString>& vec, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		str += vec[i];
		if (i != size - 1)
			str += " "; // make it work even if there are a few spaces in the original title(meaning - make another func that transforms the original title in this format
	}
}

void readWord(MyString& word)
{
	char buff[1024];
	std::cin.getline(buff, 1024);
	word = buff;
}