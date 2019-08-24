#pragma once
#include "SFML/Graphics.hpp"


class World
{
public:
	World();
	~World();
	void DrawBackground(sf::RenderWindow &window);
	void DrawForeground(sf::RenderWindow &window);
private:
	// background image
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture foregroundTexture;
	sf::Sprite foregroundSprite;

};

