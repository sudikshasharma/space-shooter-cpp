#include<iostream>
#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow myWindow{ sf::VideoMode(400, 400), "MyWindow" };
	while (myWindow.isOpen())
	{
		sf::Event event;
		while (myWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed) {
				myWindow.close();
			}
		}

	}
	return 0;
}
