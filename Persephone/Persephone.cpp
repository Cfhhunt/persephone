#include <iostream>
#include <filesystem>
#include "SFML/Graphics.hpp"
#include "Heroine.h"
#include "World.h"


int main()
{
	// init
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Persephone");// , sf::Style::Fullscreen); // add sf::Style::Fullscreen
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true); // prevents artifacts and tearing

	World world = World();
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
		
		world.DrawBackground(window);
		hero.Draw(window);
		//world.DrawForeground(window);

		window.display();
	}

	// cleanup

	return 0;
}