#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	class Application
	{
	private:
		sf::RenderWindow g_Window;
		sf::Clock clockTimer;
		float fixedFrame = 35;
	public:
		Application();
		void Run();
	private:
		void TickInternal(float deltaTime);
		void RenderInternal();
		virtual void Tick(float deltaTime);
		virtual void Render();
	};
}