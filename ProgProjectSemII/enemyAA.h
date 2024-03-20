#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include<iostream>

class enemyAA
{
	sf::Texture m_AAEnemyTexture;
	sf::Sprite m_AAEnemySprite;

	int health;
	int speed;
	int direction;
	int strength;
	bool enemyAlive;

public:

	enemyAA();
	void loadEnemy();
	sf::Sprite getEnemyBody();
	void setPositionAA();
	void setPositionAA(int posX, int posY);
	void moveAA();

};