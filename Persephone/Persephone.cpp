#include <iostream>
#include "SFML/Graphics.hpp"
#include "Heroine.h"

int main()
{
	// init
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Persephone"); // add sf::Style::Fullscreen
	window.setFramerateLimit(60);

	Heroine hero = Heroine();

	// create the clock for physics and such
	sf::Clock deltaClock;
	sf::Time dt = deltaClock.restart();

	while (window.isOpen())
	{
		// Update the clock to get elapsed time
		dt = deltaClock.restart();

		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}


		// update
		hero.Update(dt);


		// draw
		window.clear();

		hero.Draw(window);

		window.display();
	}

	// cleanup

	return 0;
}