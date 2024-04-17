#pragma once
//bullet class
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Globals.h"
class Bullet {

	sf::Sprite m_fireballSprite; // fireball sprite
	sf::Texture m_fireballDownTexture; // fireball Down texture
	sf::Texture m_fireballUpTexture; // up texture
	sf::Texture m_fireballRightTexture; // right texture
	sf::Texture m_fireballLeftTexture; // left texture

	int speed;
	int bulletDirection;
	bool isBulletActive{ false };

public:

	Bullet(); // bullet class
	sf::Sprite getBulletBody(); // get the sprite body
	void setPositionBullet(sf::Vector2f playerPosition); // setting the bullet position as the player position
	void loadBullet(); // load the bullet sprite
	void shootBulletLeft(); // shooting the bullet left
	void shootBulletUp(); // shooting the bullet up
	void shootBulletdown(); // shoot the bullet down
	void shootBulletRight(); // shoot the bullet right
	sf::FloatRect boundingBox(); //  get the bounding box, used for collision
	bool bulletMove(); // move the bullet in 4 directions
	void speedBulletUp(); // if a power up is aquired
	bool isActive();
	void setNotActive();
};