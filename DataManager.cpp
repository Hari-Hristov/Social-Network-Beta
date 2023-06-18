#pragma once
#include "DataManager.h"
#include <fstream>

void DataManager::saveUsersToFile(const MyString& path, Vector<User>& users)
{
	std::ofstream ofs(path.c_str(), std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		throw std::logic_error("Could not save the users to the database.");

	size_t size = users.getSize();
	ofs.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
	{
		users[i].saveToFile(ofs);
	}

	ofs.close();
}

void DataManager::loadUsersFromFile(const MyString& path, Vector<User>& users)
{
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw std::logic_error("Could not load the users from the database.");

	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
	{
		User userToAdd;
		userToAdd.loadFromFile(ifs);
		users.pushBack(userToAdd);
	}

	ifs.close();
}

void DataManager::saveTopicsToFile(const MyString& path, Vector<Topic>& topics)
{
	std::ofstream ofs(path.c_str(), std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		throw std::logic_error("Could not save the topics to the database.");

	size_t size = topics.getSize();
	ofs.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
	{
		topics[i].saveToFile(ofs);
	}

	ofs.close();
}

void DataManager::loadTopicsFromFile(const MyString& path, Vector<Topic>& topics)
{
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw std::logic_error("Could not load the topics from the database.");

	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
	{
		Topic topicToAdd;
		topicToAdd.loadFromFile(ifs);
		topics.pushBack(topicToAdd);
	}

	ifs.close();
}

DataManager& DataManager::getInstance()
{
	static DataManager dataManger;
	return dataManger;
}