#pragma once
#include "SFML/Graphics.hpp"

enum State {
	STATE_STANDING,
	STATE_RUNNING,
	STATE_JUMPING
};

class Heroine
{
public:
	Heroine();
	~Heroine();
	void Update(sf::Time dt);
	void Draw(sf::RenderWindow &window);
	void checkForStateChange();
	void loadTextures();

private:
	// sprites and textures
	sf::Texture heroStandRight;
	sf::Texture heroStandLeft;
	sf::Texture heroRunRight;
	sf::Texture heroRunLeft;
	sf::Texture heroJumpRight;
	sf::Texture heroJumpLeft;
	sf::Sprite heroSprite;

	// positional info
	sf::Vector2f position;
	sf::Vector2f velocity;
	float runVelocity;
	float jumpVelocity;

	State state;

	// temp
	sf::Vector2f gravity; // This will later be part of a physics engine
	float ground; // y value of where Persephone will walk
	sf::RectangleShape boundingBox;
};

