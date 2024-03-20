// Player class declaration
#pragma once
#include"SFML/Graphics.hpp"
#include"Globals.h"
#include<iostream>

class Player
{
	// private data members
	sf::Sprite m_playerSprite;
	sf::Texture m_playerTexture;

	int speed; // speed of the player character
	int image_width; //width of character sprite
	int livesCount; // amount of lives
	int health; // health of our player
	int direction; // what direction is player going

public:

	Player();
	void loadSprite();
	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);
};