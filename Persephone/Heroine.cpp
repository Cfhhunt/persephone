#include "Heroine.h"
#include <iostream>


Heroine::Heroine()
{
	position = sf::Vector2f(100.0f, 700.0f);
	velocity = sf::Vector2f(0.0f, 0.0f);

	state = STATE_STANDING;

	// Temp. rectrangle for character body
	tempBody = sf::RectangleShape();
	tempBody.setSize(sf::Vector2f(100, 70));
	tempBody.setPosition(position);
	tempBody.setFillColor(sf::Color::Cyan);
	// temp gravity
	gravity = sf::Vector2f(0.0f, 900.0f);
}


Heroine::~Heroine()
{

}

// Update
void Heroine::Update(sf::Time dt)
{
	checkForStateChange();

	switch (state)
	{
	case STATE_STANDING:
		break;
	case STATE_RUNNING:
		// make running a function of velocity and time as well
		break;
	case STATE_JUMPING:
		// allow unaffected movement in x directions
		
		break;
	}
}

void Heroine::Draw(sf::RenderWindow &window)
{
	tempBody.setPosition(position);
	// draw to the window
	window.draw(tempBody);
}

void Heroine::checkForStateChange()
{
	switch (state)
	{
	case STATE_STANDING:
		// change to STATE_RUNNING if A or D pressed


		// change to STATE_JUMPING if space pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			state = STATE_JUMPING;
			velocity.y = -1000.0f;
		}
		break;
	case STATE_RUNNING:
		// change to STATE_STANDING if no longer pressing A or D


		// change to STATE_JUMPING if space pressed

		break;
	case STATE_JUMPING:
		// change to STATE_RUNNING if collision with the ground and pressing A or D
		
		// change to STATE_STANDING if collision with the ground and not pressing A or D
		if (position.y >= 700)
		{
			state = STATE_STANDING;
			velocity.y = 0.0f;
		}

		break;
	}
}
