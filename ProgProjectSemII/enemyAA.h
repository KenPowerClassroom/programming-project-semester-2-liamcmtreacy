#pragma once
#include "ctime"
#include "cstdlib"
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class enemyAA // Aliminium Alphonso "AA" is a fast enemy who spawns more than RR, he moves in a random direction
{
	sf::Texture m_AAEnemyTexture; // AA Texture
	sf::Texture m_AAEnemyLeft; // left texture
	sf::Texture m_AAEnemyRight; // right texture
	sf::Texture m_AAEnemyUp; // up texture
	sf::Sprite m_AAEnemySprite; // AA sprite

	int speed; // how fast is he travelling
	int direction; // what direction is he facing
	bool enemyAlive; // is AA alive boolean

public:

	enemyAA();
	void loadEnemy(); // load AA onto the screen

	sf::Sprite getEnemyBody(); // sprite body
	void setPositionAA(); // set position for the enemy AA
	void setPositionAA(int xPos, int yPos); // set position for the enemy AA
	sf::FloatRect boundBox(); // used for collision detection
	void moveAA(); // allows movement
	void checkBoundry(sf::Vector2f t_pos);
	void setDirectionAA(); // Direction which the array moves
	void resetSpeed(); // this is for when the player dies the speed resets
	void speedUp(); // speed up 1
	void speedEvenFaster(); // FASTEST POSSIBLE SPEED WHEN POINTS REACH A CERTAIN AMOUNT
	sf::FloatRect AAboundingBox(); // used for collision detection
};