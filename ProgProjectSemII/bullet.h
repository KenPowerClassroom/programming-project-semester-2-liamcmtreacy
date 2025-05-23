#pragma once
//bullet class
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
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
	void shootBulletLeft(); // shooting the bullet left, in a straight line
	void shootBulletUp(); // shooting the bullet up, in a straight line
	void shootBulletdown(); // shoot the bullet down, in a straight line
	void shootBulletRight(); // shoot the bullet right, in a straight line
	sf::FloatRect boundingBox(); //  get the bounding box, used for collision
	bool bulletMove(); // move the bullet in 4 directions
	bool isActive(); // check if bullet is active
	void setNotActive(); // if the bullet collides, this sets the bool to false, so it despawns
	//both isActive and setNotActive, I asked Ken for help with in the Wednesday Lab
	void loadLaserSound(); // sound for shotting

	sf::Sound laserBlast;
	sf::SoundBuffer laserShoot;
};