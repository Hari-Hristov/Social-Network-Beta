#include "Topic.h"
#include "User.h"
#include "Util.h"
#include <stdexcept>

int main()
{
	MyString mode = commandVariables::MODES[0]; //general mode
	MyString test = "zdr";
	MyString input;
	Vector<Topic> topics;
	Vector<User> users;
	//users.pushBack(User("Petur", "Petrov", "123"));

	User* currentUser = nullptr;
	Topic* currentTopic = nullptr;
	Post* currentPost = nullptr;
	Comment* currentComment = nullptr;

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
		// ---------- ako ne ostane vreme za guest i user funcii prosto sloji edin if dali command == login ili register ako currentUser == nullptr

		//user commands
		if (contains(commandVariables::USER_FUNCS, commandVariables::USER_COMMANDS, command))
		{
			if (size != 1)
			{
				//throw std::invalid_argument("Incorrent user command.");
				std::cout << "Incorrect user command." << std::endl;
				continue;
			}

			//whoami
			if (command == "whoami")
			{
				if (currentUser)
				{
					currentUser->whoami();
				}
				else {
					//throw std::invalid_argument("There is no logged in user currently");
					std::cout << "There is no logged in user currently"<<std::endl;
				}
			}

			//logout
			else if (command == "logout")
			{
				if (currentUser)
				{
					currentUser = nullptr;
					std::cout << "Successfully logged out of the account." << std::endl;
				}
				else
					std::cout << "Logout not successfull. You are currently not logged in." << std::endl;
			}

			//register & login - nai dobre gi otdeli che == trqbva da sa im razlichni
			else
			{
				if (currentUser)
				{
					//throw here
					std::cout << "There is already a logged in user." << std::endl;
					continue;
				}
				MyString firstName = "";
				std::cout << "Enter your first name: ";
				readWord(firstName);

				MyString lastName = "";
				std::cout << "Enter your last name: ";
				readWord(lastName);

				MyString password = "";
				std::cout << "Enter your password: ";
				readWord(password);

				User newUser = User(firstName, lastName, password);

				if (command == "login")
				{
					if (currentUser)
					{
						std::cout << "There is already a logged in user. Please logout first to log into another profile." << std::endl;
						continue;
					}

					for (size_t i = 0; i < users.getSize(); i++)
					{
						if (users[i] == newUser)
							currentUser = &users[i];
					}

					if (!currentUser)
						std::cout << "Login was not successfull. There is no such user.";
					else
						std::cout << "Login was successfull." << std::endl;
				}
				else
				{
					for (size_t i = 0; i < users.getSize(); i++)
					{
						if (users[i].getFirstName() == firstName && users[i].getLastName() == lastName)
						{
							std::cout << "There is already a user with this names." << std::endl;
							break;
						}
					}

					users.pushBack(newUser);
					currentUser = &users[users.getSize() - 1];
					std::cout << "Successfully registered!" << std::endl;
				}
			}
			continue;
		}


		if (mode == "general")
		{
			if (!contains(commandVariables::TEXT_FUNCS, commandVariables::TEXT_COMMANDS, command) && !contains(commandVariables::GENERAL_FUNCS, commandVariables::GENERAL_COMMANDS, command))
			{
				std::cout << "Unavaliable command in the current mode - " << mode << std::endl;
				continue;
			}

			//create
			if (command == "create")
			{
				std::cout << "Enter you topic's title: ";
				MyString title;
				char buffTitle[1024];
				std::cin.getline(buffTitle, 1024);
				title = buffTitle;

				std::cout << "Enter your topic's desc: ";
				MyString desc;
				char buffDesc[1024];
				std::cin.getline(buffDesc, 1024);
				desc = buffDesc;

				topics.pushBack(Topic(title, "Petur", desc));
			}
			//search
			else if (command == "search")
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
						std::cout << "Successfully opened the topic: " << currentTopic->getTitle() << std::endl;
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
					else
					{
						std::cout << "Successfully opened the topic: " << currentTopic->getTitle() << std::endl;
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

			//open
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
				;
				currentTopic->post(title, desc);

			}
			//p_open
			else if (command == "p_open")
			{
				if (size == 1) {
					std::cout << "Command in p_open is too short" << std::endl;
					continue;
					//throw std::length_error("Command [p_open] requires id or title.");
				}


				if (size == 2 && isPositiveNumber(v[1]))
				{
					unsigned postId = v[1].toUnsigned();
					bool found = false;

					for (size_t i = 0; i < currentTopic->posts.getSize(); i++)
					{
						if (postId == currentTopic->posts[i].getId())
						{
							found = true;
							mode = "post";
							currentPost = &currentTopic->posts[i];
							break;
						}
					}

					if (!found)
					{
						throw std::invalid_argument("There is no post found with this id.");
						//no match found with this id (more generalized, for the namespace with the errors
					}
					else
					{
						std::cout << "Successfully opened the post." << std::endl;
					}
				}
				else
				{
					MyString postTitle = "";
					addText(postTitle, v, size);

					bool foundTopic = false;

					for (size_t i = 0; i < currentTopic->posts.getSize(); i++)
					{
						if (currentTopic->posts[i].getTitle() == postTitle)
						{
							foundTopic = true;
							currentPost = &currentTopic->posts[i];
							mode = "post";
							break;
						}
					}

					if (!foundTopic)
					{
						std::cout << "There is no post with this title in the current topic." << std::endl;
						//throw std::invalid_argument("There is no post with this title in the current topic.");
					}
					else
					{
						std::cout << "Successfully opened the post." << std::endl;
					}
				}
			}
			//quit
			else
			{
				if (size != 1)
					throw std::invalid_argument("Do not add anything after the comment command.");

				mode = "general";
				std::cout << "Successfully exited the topic." << std::endl;
			}
		}

		else if (mode == "post")
		{
			if (!contains(commandVariables::POST_FUNCS, commandVariables::POST_COMMNADS, command))
			{
				std::cout << "Unavaliable command in the current mode - " << mode << std::endl;
				continue;
			}

			//comment
			if (command == "comment")
			{
				if (size != 1)
					throw std::invalid_argument("Do not add anything after the comment command.");

				MyString text = "";
				std::cout << "Write what's on your mind: ";
				char buffText[1024];
				std::cin.getline(buffText, 1024);
				text = buffText;

				currentPost->comment("Petur", text);
			}

			//comments
			else if (command == "comments")
			{
				if (size != 1)
					throw std::invalid_argument("Do not add anything after the comments command.");

				currentPost->showComments();
			}

			//reply
			else if (command == "reply") //-----------------
			{
				//posle
			}

			//p_close
			else if (command == "p_close")
			{
				if (size != 1)
					throw std::invalid_argument("Do not add anything after the comment command.");

				mode = "topic";
				std::cout << "Successfully exited the post." << std::endl;
			}

			//upvote & downvote
			else
			{
				if (size != 2)
					throw std::invalid_argument("Upvote command takes only id.");

				if (!isPositiveNumber(v[1]))
					throw std::invalid_argument("Id is not a positive number");

				unsigned idToVote = v[1].toUnsigned();

				try
				{
					currentComment = &currentPost->getCommentById(idToVote);
				}
				catch (const std::invalid_argument& ex)
				{
					std::cout << ex.what() << std::endl;
					continue;
				}
				unsigned userId = currentUser->getId();

				//upvote
				if (command == "upvote")
				{
					if (currentComment->hasBeenDislikedBy(userId))
					{
						currentComment->removeUserIdFromDisliked(userId);
						currentUser->removePoint();
					}

					if (currentComment->hasBeenLikedBy(userId))
					{
						currentComment->removeUserIdFromLiked(userId);
						currentUser->removePoint();
					}
					else
					{
						currentComment->addUserIdToLiked(userId);
						currentUser->addPoint();
					}
				}
				//downvote
				else
				{
					if (currentComment->hasBeenLikedBy(userId))
					{
						currentComment->removeUserIdFromLiked(userId);
						currentUser->removePoint();
					}

					if (currentComment->hasBeenDislikedBy(userId))
					{
						currentComment->removeUserIdFromDisliked(userId);
						currentUser->removePoint();
					}
					else
					{
						currentComment->addUserIdToDisliked(userId);
						currentUser->addPoint();
					}
				}
			}
		}
	}
}
