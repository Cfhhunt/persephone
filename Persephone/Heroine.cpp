#include "Heroine.h"


Heroine::Heroine()
{
	state_ = STANDING_STATE;
	direction = 1;
	x = 200;
	y = 700;
}


Heroine::~Heroine()
{
}

void Heroine::handleInput()
{
	switch (state_)
	{
	case STANDING_STATE:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			x += speed;
			direction = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			x -= speed;
			direction = -1;
		}
		break;
	case RUNNING_STATE:
		break;
	case JUMPING_STATE:
		break;
	}
}

void Heroine::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setPosition(x, y);
	rectangle.setFillColor(sf::Color::Cyan);
	window.draw(rectangle);
}