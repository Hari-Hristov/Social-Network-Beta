#include "Engine.h"
#include <stdexcept>

int main()
{
	// save into binary files the users and topics and then load them when the program starts
	Engine::getInstance().run();
}
