#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class enemyCC
{
	sf::Sprite m_enemyCCsprite;
	sf::Texture CCTexture;
	sf::Texture CCTextureRight;

	int CCspeed;
	int directionCC;
	bool CCalive;

public:
	enemyCC();
	void loadCCenemy();

	sf::Sprite getCCBody(); // sprite body
	void setPositionCC(); // set position for the enemy AA
	void setPositionCC(int xPos, int yPos); // set position for the enemy AA
	sf::FloatRect boundBoxCC(); // used for collision detection
	void moveCC(); // allows movement
	void checkBoundryCC(sf::Vector2f t_pos);
	void speedUpCC(); // speed up 1
	void maxSpeedCC(); // FASTEST POSSIBLE SPEED WHEN POINTS REACH A CERTAIN AMOUNT
	void changeDirection(); // send the enemy in a random direction
	void resetSpeed(); // reset the speed when the player dies
};