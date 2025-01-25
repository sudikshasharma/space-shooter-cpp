#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

ss::Application::Application():g_Window{sf::VideoMode(1000,1000),"SpaceShooter"}
{
}

void ss::Application::Run()
{
	float timePassed = 0;
	float deltaTime = 1 / fixedFrame;
	while (g_Window.isOpen())
	{
		sf::Event event;
		while (g_Window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed) {
				g_Window.close();
			}
		}
		float timeCaptured = clockTimer.restart().asSeconds(); // Get time passed add to variable and then restart the clock
		timePassed += timeCaptured;
		// To print fps (variable), uncomment below line and comment the rest of the code below it
		//std::cout << "FPS: " << 1 / timeCaptured << std::endl;
		// Check if timepassed is more than the delta time, if so, perform an update (For fixed frame update)
		while (timePassed > deltaTime)
		{
			timePassed -= deltaTime;
			TickInternal(deltaTime);
			RenderInternal();
		}
	}
}

void ss::Application::Tick(float deltaTime)
{
	std::cout << "Rendered Frame Rate : " << 1 / deltaTime << std::endl;
}

void ss::Application::TickInternal(float deltaTime)
{
	Tick(deltaTime);
}

void ss::Application::Render()
{
	// drawing rectangle
	sf::RectangleShape rect{ sf::Vector2f(100,100)};
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(g_Window.getSize().x/2, g_Window.getSize().y / 2));
	g_Window.draw(rect);
	// drawing sphere
	sf::CircleShape cir{ 40 };
	cir.setFillColor(sf::Color::Blue);
	cir.setOrigin(50,50);
	cir.setPosition(sf::Vector2f(g_Window.getSize().x / 2, g_Window.getSize().y / 2));
	g_Window.draw(cir);
}

void ss::Application::RenderInternal()
{
	g_Window.clear();
	Render();
	g_Window.display();
}
