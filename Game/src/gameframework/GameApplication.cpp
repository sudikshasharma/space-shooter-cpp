#include <framework/Application.h>
#include "gameframework/GameApplication.h"

ss::Application* GetApplication()
{
	return new ss::GameApplication();
}