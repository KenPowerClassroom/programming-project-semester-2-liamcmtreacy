#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class enemyAA
{
	sf::Texture m_AAEnemyTexture; // AA Texture
	sf::Sprite m_AAEnemySprite; // AA sprite

	int health; // how much health does he have
	int speed; // how fast is he travelling
	int direction; // what direction is he facing
	int strength; // strength of enemy
	int image_width;
	bool enemyAlive; // is AA alive boolean

public:

	enemyAA();
	void loadEnemy(); // load AA onto the screen

	sf::Sprite getEnemyBody(); // sprite body
	void setPositionAA(); // set position for the enemy AA
	void setPositionAA(int xPos, int yPos); // set position for the enemy AA
	void moveAA(); // allows movement
	void checkBoundry(sf::Vector2f t_pos);
	void setDirectionAA(); // Random Direction
};