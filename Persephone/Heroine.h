#pragma once
#include "SFML/Graphics.hpp"
enum State { STANDING_STATE, RUNNING_STATE, JUMPING_STATE };

class Heroine
{
public:
	Heroine();
	~Heroine();

	// draw
	void draw(sf::RenderWindow& window);

	// update

	// handleInput
	void handleInput();

private:
	// state
	enum State state_;
	int x;
	int y;
	int width;
	int height;
	int direction;
	float vel;
	int speed = 10;


	// sprites
};
