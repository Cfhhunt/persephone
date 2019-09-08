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
	void UpdateSprite();
	void ResetSprite();
	sf::Vector2f GetPosition();
	sf::Vector2f GetVelocity();

private:
	// Fields

	// sprites and textures
	sf::Texture standRightTexture;
	sf::Texture standLeftTexture;
	sf::Texture runRightTexture;
	sf::Texture runLeftTexture;
	sf::Texture jumpRightTexture;
	sf::Texture jumpLeftTexture;
	sf::Sprite heroSprite;
	int spriteWidth;
	int frameCounter;

	// positional info
	sf::Vector2f position;
	sf::Vector2f velocity;
	float runVelocity;
	float jumpVelocity;
	int direction; // 1 for right, -1 for left


	// State
	State state;
	State previousState;
	
	// STATE_STANDING

	// STATE_RUNNING

	// STATE_JUMPING

	// STATE_DOUBLE_JUMPING


	// Methods

	// Init methods
	void loadTextures();

	// Actions

	// Run

	// Jump

	// Stand


	// Handle Player

	// State change
	void checkForStateChange();

	// Update sprite

	// update texture

	// Update position



	// temp
	sf::Vector2f gravity; // This will later be part of a physics engine
	float ground; // y value of where Persephone will walk 
	int frameLoop;
};

