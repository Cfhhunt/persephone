#pragma once
#include <SFML/Graphics.hpp>

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
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	float runVelocity;
	float jumpVelocity;

	State state;

	// temp
	sf::RectangleShape tempBody; // temp sprite
	sf::Vector2f gravity; // This will later be part of a physics engine
	float ground; // y value of where Persephone will walk
};

