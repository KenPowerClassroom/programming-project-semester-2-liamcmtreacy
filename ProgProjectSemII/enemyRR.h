#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class enemyRR // Rusty Raymond "RR" is a follower enemy, he is slower but follows the player
{
	sf::Texture RRTexture; // RR Texture
	sf::Sprite RRSprite; // RR sprite
	sf::Texture RRupText; // RR Texture
	sf::Texture RRleftText; // RR Texture
	sf::Texture RRrightTexture; // RR Texture

	int speed; // how fast is he travelling
	int RRdirection; // what direction is he facing
	bool RRalive; // is RR alive boolean

public:

	enemyRR();
	void loadEnemy(); // load RR onto the screen

	sf::Sprite getRRbody(); // sprite body
	void setPositionRR(); // set position for the enemy RR
	void setPositionRR(int xPos, int yPos); // set position for the enemy RR
	void moveRR(const sf::Vector2f& playerPosition); // follow the player
	void checkBoundryRR(sf::Vector2f t_pos); //boundrychecking
	sf::FloatRect getBoundingBoxRR(); // used for collision detection
};