#pragma once
//bullet class
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Globals.h"
class Bullet {

	sf::Sprite m_fireballSprite;
	sf::Texture m_fireballDownTexture;
	sf::Texture m_fireballUpTexture;
	sf::Texture m_fireballRightTexture;
	sf::Texture m_fireballLeftTexture;

	int speed;
	int bulletDirection;
	bool isBulletActive{ false };

public:

	Bullet();
	sf::Sprite getBulletBody();
	void setPositionBullet(sf::Vector2f playerPosition);
	void loadBullet();
	void shootBulletLeft();
	void shootBulletUp();
	void shootBulletdown();
	void shootBulletRight();
	sf::FloatRect boundingBox();
	bool bulletMove();
	void speedBulletUp();
};