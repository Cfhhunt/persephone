#include "World.h"



World::World(Heroine hero)
{
	worldx = 0;
	worldy = 0;
	this->hero = hero;
	backgroundTexture.loadFromFile("../images/background.jpg");
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	backgroundSprite.setTexture(backgroundTexture);
	foregroundTexture.loadFromFile("../images/foreground.png");
	foregroundSprite.setTexture(foregroundTexture);
}


World::~World()
{
}

void World::DrawBackground(sf::RenderWindow & window)
{
	if (hero.GetPosition().x > 400 && hero.GetVelocity().x > 0) {
		worldx = worldx + 10;
		backgroundSprite.setTextureRect(sf::IntRect(worldx, worldy, 1920, 1080));
	}
	window.draw(backgroundSprite);
}

void World::DrawForeground(sf::RenderWindow & window)
{
	window.draw(foregroundSprite);
}