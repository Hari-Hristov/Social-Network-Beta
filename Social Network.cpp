#include "Topic.h"
#include "Util.h"
#include <stdexcept>

int main()
{
	MyString mode = commandVariables::MODES[0]; //general mode
	MyString test = "zdr";
	MyString input;
	Vector<Topic> topics;
	Topic currentTopic;
	
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
			std::cout << "Please enter a command.";
			throw std::invalid_argument("Please enter a command.");
		}

		MyString command = v[0];

		if (mode == "general")
		{
			if (!contains(commandVariables::TEXT_FUNCS, commandVariables::TEXT_COMMANDS, command) &&	  !contains(commandVariables::generalFuncs, commandVariables::GENERAL_COMMANDS, command))
			{
				std::cout << "Unavaliable command in the current mode - " << mode << std::endl;
				continue;
			}

			//search
			if (command == "search")
			{
				size_t size = v.getSize();
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
			if (command == "open")
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
							currentTopic = topics[i];
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
							currentTopic = topics[i];
							found = true;
							mode = "topic";
							break;
						}

						if (!found)
						{
							std::cout << "invalid title." << std::endl;
							//throw std::out_of_range("There is no topic found with this title.");
						}
					}
				}
			}
		}
		else if (mode == "topic")
		{

			std::cout << "Veche si v topic" << std::endl;
		}
		else if (mode == "post")
		{
			std::cout << "Veche si vuv post" << std::endl;
		}

		//search is implemented !


		if (v.getSize() > 2 || v.getSize() == 0)
		{
			std::cout << "greshka";
			throw std::invalid_argument("Not a valid command.");
		}


		if (contains(commandVariables::generalFuncs,
			commandVariables::GENERAL_COMMANDS, command))
		{

		}
		else if (contains(commandVariables::postFuncs,
			commandVariables::POST_COMMNADS, command))
		{

		}
		else if (contains(commandVariables::topicFuncs,
			commandVariables::TOPIC_COMMANDS, command))
		{

		}
		else
		{
			std::cout << "nqq takava komanda" << std::endl;
			//throw std::invalid_argument("Invalid command.");
		}
	}
}
