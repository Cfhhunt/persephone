#include "Heroine.h"
#include <iostream>


Heroine::Heroine()
{
	// positional info
	ground = 835.0f; // temp. val for ground collisions
	position = sf::Vector2f(100.0f, ground);
	velocity = sf::Vector2f(0.0f, 0.0f);
	runVelocity = 250.0f;
	jumpVelocity = -800.0f;
	
	// load textures
	loadTextures();

	// sprite
	heroSprite.setTexture(heroStandRight);
	heroSprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	heroSprite.setPosition(position);
	heroSprite.setScale(.5, .5); // temp. The sprites are bigger than they should be, fix the sprites then delete this

	// current state(s)
	state = STATE_STANDING;

	// temp gravity
	gravity = sf::Vector2f(0.0f, 2200.0f);
	
	 
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

	// Update sprite and collision stuff
	heroSprite.setPosition(position);
}

void Heroine::Draw(sf::RenderWindow &window)
{
	// TODO: Animate(state, vel, position, sprite, texture)

	// draw to the window
	window.draw(heroSprite);
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
		if ((position.y >= ground) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) // TODO: check for collision
		{
			state = STATE_RUNNING;
			velocity.y = 0.0f;
		}

		// change to STATE_STANDING if collision with the ground AND not pressing A or D
		else if (position.y >= ground) // TODO: check for collision
		{
			state = STATE_STANDING;
			velocity.y = 0.0f;
		}

		break;
	}
}

void Heroine::loadTextures()
{
	heroStandRight.loadFromFile("../images/Heroine/StandRight.png");
	heroStandLeft.loadFromFile("../images/Heroine/StandLeft.png");
	heroRunRight.loadFromFile("../images/Heroine/RunRight.png");
	heroRunLeft.loadFromFile("../images/Heroine/RunLeft.png");
	heroJumpRight.loadFromFile("../images/Heroine/JumpRight.png");
	heroJumpLeft.loadFromFile("../images/Heroine/JumpLeft.png");
}
