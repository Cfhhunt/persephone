#include <iostream>
#include "SFML/Graphics.hpp"
#include "Heroine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Persephone", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	// init

	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}

		// update



		// draw
		window.clear();

		window.display();
	}

	// cleanup

	return 0;
}