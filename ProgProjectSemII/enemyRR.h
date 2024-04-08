#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class enemyRR
{
	sf::Texture RRTexture; // AA Texture
	sf::Sprite RRSprite; // AA sprite

	int RRspeed; // how fast is he travelling
	int RRdirection; // what direction is he facing
	int RRstrength; // strength of enemy
	int image_width;
	bool RRalive; // is AA alive boolean

public:

	enemyRR();
	void loadEnemy(); // load AA onto the screen

	sf::Sprite getRRbody(); // sprite body
	void setPositionRR(); // set position for the enemy AA
	void setPositionRR(int xPos, int yPos); // set position for the enemy AA
	void moveRR(); // allows movement
	void checkBoundry(sf::Vector2f t_pos);
	void setDirectionRR(); // Random Direction
};