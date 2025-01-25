#include "Init.h"
#include "framework/Application.h"

int main()
{
	ss::Application* game = GetApplication();
	game->Run();
	return 0;
}
