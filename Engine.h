#pragma once

class Engine
{
	Engine() = default;
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

public:
	void run();
	static Engine& getInstance();
};