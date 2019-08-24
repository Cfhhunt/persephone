#include "World.h"



World::World()
{
	backgroundTexture.loadFromFile("../images/background.jpg");
	backgroundSprite.setTexture(backgroundTexture);
	foregroundTexture.loadFromFile("../images/foreground.png");
	foregroundSprite.setTexture(foregroundTexture);
}


World::~World()
{
}

void World::DrawBackground(sf::RenderWindow & window)
{
	window.draw(backgroundSprite);
}

void World::DrawForeground(sf::RenderWindow & window)
{
	window.draw(foregroundSprite);
}