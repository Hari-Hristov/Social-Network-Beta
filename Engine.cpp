#pragma once
#include "Engine.h"
#include "ConstantsAndIncludes.h"
#include "Util.h"

Engine& Engine::getInstance()
{
	static Engine engine;
	return engine;
}

void Engine::run()
{
	MyString mode = commandVariables::MODES[0]; //general mode
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

	while (true)
	{
		try
		{
			std::cout << '>';
			readWord(input);

			if (input == "exit")
			{
				std::cout << "exit-nahme" << std::endl;
				//save all the current data here
				return;
			}

			Vector<MyString> v = split(input, ' ');

			if (v.getSize() == 0)
				throw std::invalid_argument("Please enter a command.");

			MyString command = v[0];
			size_t size = v.getSize();


			if (!currentUser && command != "login" && command != "register")
				throw std::invalid_argument("We currently do not support guest users. Please login or register first to continue using the program.");

			//user commands
			if (contains(commandVariables::USER_FUNCS, commandVariables::USER_COMMANDS, command))
			{
				if (size != 1)
					throw std::invalid_argument("Incorrent user command.");

				//whoami
				if (command == "whoami")
				{
					if (currentUser)
						currentUser->whoami();
					else
						throw std::invalid_argument("There is no logged in user currently");
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

				//login & register
				else
					UserCommandFactory::getInstance().getCommand(command)->execute(currentUser, users, v);

				continue;
			}

			//general mode
			if (mode == "general")
			{
				if (!contains(commandVariables::TEXT_FUNCS, commandVariables::TEXT_COMMANDS, command) && !contains(commandVariables::GENERAL_FUNCS, commandVariables::GENERAL_COMMANDS, command))
					throw std::invalid_argument("Unavaliable command in general mode.");

				// create, search and about
				if (command != "open")
				{
					//kak da ukaja che currentUser tuk shte e readOnly
					try
					{
						GeneralNavigationFactory::getInstance().getCommand(command)->execute(topics, v, currentUser);

					}
					catch (const std::bad_cast& ex)
					{
						std::cout << ex.what() << std::endl;
					}
					catch (const std::invalid_argument& ex)
					{
						std::cout << ex.what() << std::endl;
					}
				}

				//open
				else
				{
					try
					{
						OpenTopic::getInstance().execute(topics, currentTopic, mode, v);
					}
					catch (const std::out_of_range& ex)
					{
						std::cout << ex.what() << std::endl;
					}
					catch (const std::invalid_argument& ex)
					{
						std::cout << ex.what() << std::endl;
					}
				}
			}

			//topic mode
			else if (mode == "topic")
			{
				if (!contains(commandVariables::TOPIC_FUNCS, commandVariables::TOPIC_COMMANDS, command))
					throw std::invalid_argument("Unavaliable command in topic mode.");

				//post
				if (command == "post")
				{
					if (size != 1)
						throw std::length_error("Do not add anything after the post command.");

					std::cout << "What will be your post's title: ";
					MyString title = "";
					readWord(title);

					std::cout << "What do you want to post(maximum number charecters is 1024): ";
					MyString desc = "";
					readWord(desc);

					currentTopic->post(title, desc);

				}
				//p_open
				else if (command == "p_open")
					OpenPost::getInstance().execute(currentPost, currentTopic, mode, v);
				//quit
				else
				{
					if (size != 1)
						throw std::length_error("Do not add anything after the quit command.");

					mode = "general";
					std::cout << "Successfully exited the topic." << std::endl;
				}
			}

			//post mode
			else if (mode == "post")
			{
				if (!contains(commandVariables::POST_FUNCS, commandVariables::POST_COMMNADS, command))
					throw std::invalid_argument("Unavaliable command post mode");

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
						throw std::length_error("Do not add anything after the comments command.");

					currentPost->showComments();
				}

				//reply
				else if (command == "reply") //-----------------
				{
					std::cout << "TBI" << std::endl;
				}

				//p_close
				else if (command == "p_close")
				{
					if (size != 1)
						throw std::length_error("Do not add anything after the comment command.");

					mode = "topic";
					std::cout << "Successfully exited the post." << std::endl;
				}

				//upvote & downvote
				else
					VoteCommentFactory::getInstance().getCommand(command)->execute(currentUser, currentPost, currentComment, v);
			}
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}