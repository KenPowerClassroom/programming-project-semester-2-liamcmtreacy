#pragma once
//bullet class
#include "SFML/Graphics.hpp"
#include <iostream>
class Bullet {

	sf::Sprite m_fireballSprite;
	sf::Texture m_fireballTexture;

	int speed;
	int direction;
	int bulletStrength;
	bool didPlayerShoot{ false };

public:

	Bullet();
	void loadBullet();
	void setPositionBullet();
	void speedBulletUp();
};