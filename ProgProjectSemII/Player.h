// Player class declaration
#pragma once

#include"SFML/Graphics.hpp"
#include"Globals.h"
#include<iostream>

class Player
{
	// private data members
	sf::Sprite m_playerSprite; // player Sprite
	sf::Texture m_playerTexture; //down Texture
	sf::Texture m_playerLeftTexture; // left texture
	sf::Texture m_playerRightTexture; // right texture
	sf::Texture m_playerUpTexture; // up texture


	int speed; // speed of the player character
	int image_width; //width of character sprite
	int health; // health of our player
	int PlayerDirection; // what direction is player going
	bool isPlayerLiving{ true };

public:

	Player();
	void loadSprite(); // load the player
	sf::Sprite getBody(); // return the body
	void setPosition(); // set position of the player starting
	void setPosition(int xPos, int yPos);
	void moveLeft(); // move left
	void moveRight(); // move right
	void moveUp(); // move up
	void moveDown(); // move down
	void boundry(sf::Vector2f t_pos); // boundry checking
	sf::FloatRect playerBoundingBox(); // too see if the player hit an enemy, used in collision detection
	bool isPlayerAlive(); // see if the player is alive
	bool playerdead(); // check is the player dead
};