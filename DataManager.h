#pragma once
#include "User.h"
#include "Vector.hpp"
#include "Topic.h"

class DataManager
{
	DataManager() = default;
	DataManager(const DataManager&) = delete;
	DataManager& operator=(const DataManager&) = delete;

public:
	void saveUsersToFile(const MyString& path, Vector<User>& users);
	void loadUsersFromFile(const MyString& path, Vector<User>& users);

	void saveTopicsToFile(const MyString& path, Vector<Topic>& topics);
	void loadTopicsFromFile(const MyString& path, Vector<Topic>& topics);

	static DataManager& getInstance();
};