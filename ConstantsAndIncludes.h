#include "Topic.h"
#include "User.h"
#include "Util.h"
#include <stdexcept>
#include "UserManagement/UserCommandFactory.h"
#include "GeneralNavigation/GeneralNavigationFactory.h"
#include "OpenTopic.h"
#include "OpenPost.h"
#include "VoteComment/VoteCommentFactory.h"
#include "DataManager.h"
#include <fstream>

const MyString USERS_FILE_PATH = "users.txt";
const MyString TOPICS_FILE_PATH = "topics.txt";

namespace commandVariables
{
	const unsigned MODES_COUNT = 3;
	const unsigned USER_COMMANDS = 4;
	const unsigned TEXT_COMMANDS = 1;
	const unsigned GENERAL_COMMANDS = 3;
	const unsigned TOPIC_COMMANDS = 4;
	const unsigned POST_COMMNADS = 6;

	static const MyString MODES[MODES_COUNT] =
	{
		"general", "topic", "post"
	};

	static const MyString USER_FUNCS[USER_COMMANDS] =
	{
		"login", "register", "whoami", "logout"
	};

	static const MyString TEXT_FUNCS[TEXT_COMMANDS] =
	{
		"search"
	};

	static const MyString GENERAL_FUNCS[GENERAL_COMMANDS] =
	{
		"open", "about", "create"
	};
	static const MyString TOPIC_FUNCS[TOPIC_COMMANDS] = {
		"post", "posts", "p_open", "quit"
	};

	static const MyString POST_FUNCS[POST_COMMNADS] = {
		"comment", "comments", "reply", "upvote", "downvote", "p_close"
	};
}