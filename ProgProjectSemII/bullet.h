#pragma once
//bullet class
#include "SFML/Graphics.hpp"
#include <iostream>
class Bullet {

	sf::Sprite m_fireballSprite;
	sf::Texture m_fireballDownTexture;
	sf::Texture m_fireballUpTexture;
	sf::Texture m_fireballRightTexture;
	sf::Texture m_fireballLeftTexture;

	int speed;
	int bulletDirection;
	int bulletStrength;
	bool didPlayerShoot{ false };

public:

	Bullet();
	void loadBullet();
	void shootBulletLeft();
	void shootBulletUp();
	void shootBulletdown();
	void shootBulletRight();
	void setPositionBullet();
	void speedBulletUp();
};