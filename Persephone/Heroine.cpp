#include "Heroine.h"
#include <iostream>


Heroine::Heroine()
{
	position = sf::Vector2f(100.0f, 700.0f);
	velocity = sf::Vector2f(0.0f, 0.0f);
	runVelocity = 250.0f;
	jumpVelocity = -1200.0f;

	state = STATE_STANDING;

	// Temp. rectrangle for character body
	tempBody = sf::RectangleShape();
	tempBody.setSize(sf::Vector2f(100, 70));
	tempBody.setPosition(position);
	tempBody.setFillColor(sf::Color::Cyan);
	// temp gravity
	gravity = sf::Vector2f(0.0f, 2000.0f);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x = -runVelocity;
			position.x = position.x + velocity.x * dt.asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = runVelocity;
			position.x = position.x + velocity.x * dt.asSeconds();
		}
		break;
	case STATE_JUMPING:
		velocity.y = velocity.y + gravity.y * dt.asSeconds();
		position.y = position.y + velocity.y * dt.asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x = -runVelocity;
			position.x = position.x + velocity.x * dt.asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = runVelocity;
			position.x = position.x + velocity.x * dt.asSeconds();
		}
		break;
	}
}

void Heroine::Draw(sf::RenderWindow &window)
{
	tempBody.setPosition(position);
	// draw to the window
	window.draw(tempBody);
}

// This checks for state change, changes it if needed, and initializes the new state (ie. changing velocity)
void Heroine::checkForStateChange()
{
	switch (state)
	{
	case STATE_STANDING:
		// change to STATE_RUNNING if A or D pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			state = STATE_RUNNING;
		}

		// change to STATE_JUMPING if space pressed
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			state = STATE_JUMPING;
			velocity.y = jumpVelocity;
		}
		break;
	case STATE_RUNNING:
		// change to STATE_STANDING if no longer pressing A or D
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			state = STATE_STANDING;
			velocity.x = 0;
		}

		// change to STATE_JUMPING if space pressed
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			state = STATE_JUMPING;
			velocity.y = jumpVelocity;
		}
		break;
	case STATE_JUMPING:
		// change to STATE_RUNNING if collision with the ground AND pressing A or D
		if ((position.y >= 700) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) // TODO: check for collision
		{
			state = STATE_RUNNING;
			velocity.y = 0.0f;
		}

		// change to STATE_STANDING if collision with the ground AND not pressing A or D
		else if (position.y >= 700) // TODO: check for collision
		{
			state = STATE_STANDING;
			velocity.y = 0.0f;
		}

		break;
	}
}
