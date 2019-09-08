#pragma once
#include "SFML/Graphics.hpp"
#include "Heroine.h"


class World
{
public:
	World(Heroine hero);
	~World();
	void DrawBackground(sf::RenderWindow &window);
	void DrawForeground(sf::RenderWindow &window);
private:
	Heroine hero;
	// background image
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture foregroundTexture;
	sf::Sprite foregroundSprite;
	int worldx;
	int worldy;

};

