#include "Topic.h"
#include "Util.h"
#include <stdexcept>

int main()
{
	MyString mode = commandVariables::MODES[0]; //general mode
	MyString test = "zdr";
	MyString input;
	Vector<Topic> topics;
	Topic* currentTopic = nullptr;
	
	topics.pushBack(Topic("guza mi brat", "petur", "abc"));
	topics.pushBack(Topic("dupeto mi brat", "petur", "abc"));
	while (true) //change v to something meaningful
	{
		char buff[1024];
		std::cout << '>';
		std::cin.getline(buff, 1024);
		input = buff;

		if (input == "exit")
		{
			std::cout << "exit-nahme" << std::endl;
			//save all the current data here
			return 0;
		}
		Vector<MyString> v = split(input, ' ');

		if (v.getSize() == 0)
		{
			throw std::invalid_argument("Please enter a command.");
		}

		MyString command = v[0];
		size_t size = v.getSize();

		if (mode == "general")
		{
			if (!contains(commandVariables::TEXT_FUNCS, commandVariables::TEXT_COMMANDS, command) &&	  !contains(commandVariables::GENERAL_FUNCS, commandVariables::GENERAL_COMMANDS, command))
			{
				std::cout << "Unavaliable command in the current mode - " << mode << std::endl;
				continue;
			}

			//search
			if (command == "search")
			{
				
				if (size == 1)
				{
					throw std::invalid_argument("Please enter a text to search.");
				}
				MyString textToSearch = "";
				addText(textToSearch, v, size);

				Vector<Topic> result;
				for (size_t i = 0; i < topics.getSize(); i++)
				{
					if (topics[i].containsTextInTitle(textToSearch))
						result.pushBack(topics[i]);
				}

				//print result - ako e nula res.size - print nqma namereni temi
				size_t resultSize = result.getSize();

				if (resultSize == 0)
				{
					std::cout << "There are no matches found." << std::endl;
				}
				else
				{
					for (size_t i = 0; i < resultSize; i++)
					{
						result[i].print();
					}
				}
				continue;
			}

			//open
			else if (command == "open")
			{
				size_t size = v.getSize();

				if (size == 1)
				{
					//cout that and continue at the bottom or try catch it and continue(better approach)
					throw std::invalid_argument("Please enter a title of the topic you want to open.");
				}
				else if (size == 2 && isPositiveNumber(v[1]))
				{
					unsigned searchedId = v[1].toUnsigned();
					bool found = false;

					for (size_t i = 0; i < size; i++)
					{
						if (topics[i].getId() == searchedId)
						{
							currentTopic = &topics[i];
							found = true;
							mode = "topic";
							break;
						}
					}
					if (!found)
					{
						std::cout << "invalid id." << std::endl;
						//throw std::out_of_range("There is no topic found with this id.");
					}
					else
					{
						std::cout << "Successfully opened the topic." << std::endl;
					}
				}
				else
				{
					//(mode = "topic"), if the validation is successful !!!!
					MyString title = "";
					addText(title, v, size);

					bool found = false;
					for (size_t i = 0; i < topics.getSize(); i++)
					{
						if (topics[i].getTitle() == title)
						{
							currentTopic = &topics[i];
							found = true;
							mode = "topic";
							break;
						}
					}

					if (!found)
					{
						std::cout << "invalid title." << std::endl;
						//throw std::out_of_range("There is no topic found with this title.");
					}
				}
			}

			//about
			else
			{
				if (size != 2 || !isPositiveNumber(v[1]))
					throw std::bad_cast(); // cout smth when you catch it

				unsigned searchedId = v[1].toUnsigned();
				bool found = false;

				for (size_t i = 0; i < topics.getSize(); i++)
				{
					if (topics[i].getId() == searchedId)
					{
						topics[i].print();
						found = true;
						break;
					}
				}

				if (!found)
					throw std::invalid_argument("Cannot show information on this topic because it does not exit.");
			}
		}

		else if (mode == "topic")
		{
			if (!contains(commandVariables::TOPIC_FUNCS, commandVariables::TOPIC_COMMANDS, command))
			{
				std::cout << "Unavaliable command in the current mode - " << mode << std::endl;
				continue;
			}

			if (command == "post")
			{
				if (size != 1)
					throw std::invalid_argument("Do not add anything after the post command.");

				MyString title = "";
				MyString desc = "";
				std::cout << "What will be your post's title: ";
				char buffTitle[1024];
				std::cin.getline(buffTitle, 1024);
				title = buffTitle;
				std::cout << "What do you want to post(maximum number charecters is 1024): ";
				char buffDesc[1024];
				std::cin.getline(buffDesc, 1024);
				desc = buffDesc;

				Post toAdd = Post(title, desc);
				currentTopic->post(toAdd);

			}
			else if (command == "p_open")
			{
				//vliza v post mode pri validen p_open command
			}
			else //quit
			{
				mode = "general";
				std::cout << "Successfully exited the topic." << std::endl;
			}
		}
		else if (mode == "post")
		{
			std::cout << "Veche si vuv post" << std::endl;
		}
	}
}
