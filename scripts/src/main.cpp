#include<memory>
#include<iostream>
#include<SFML/Graphics.hpp>
#include"framework/Application.h"

int main()
{
	std::unique_ptr<ss::Application> newGame = std::make_unique<ss::Application>();
	newGame->Run();
	return 0;
}
