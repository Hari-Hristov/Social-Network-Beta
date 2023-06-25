#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Topic.h"

bool isPositiveNumber(const MyString& str);
unsigned toUnsigned(const MyString& str);
bool contains(const MyString* arr, const unsigned size, const MyString el);
const Vector<MyString> split(const MyString& input, const char separator);
void addText(MyString& str, const Vector<MyString>& vec, size_t size);
void readWord(MyString& word);
void saveWordToFile(std::ofstream& ofs, const MyString& word);
void displayOption(const MyString* vec, unsigned size);
void printVector(const MyString* vec, unsigned size);