// Name: Liam Treacy
// Login: started MARCH 20th 2024 9:08am
// Date: 20/03/24
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file
#include "enemyAA.h" // enemyAA header
#include "Player.h" // player header
#include "bullet.h" // bullet header
#include "enemyRR.h" //RR header


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file" << std::endl;
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	m_score.setFont(m_font);  // set the font for the text
	m_score.setCharacterSize(24); // text size
	m_score.setFillColor(sf::Color::White); // color
	m_score.setPosition(10, 40);  // score total and its position on the screen

	m_healthBar.setFillColor(sf::Color::Red);
	m_healthBar.setSize(sf::Vector2f{100.0f, 50.0f });
	m_healthBar.setPosition(1400.0f, 0.0f);

	m_lives.setFont(m_font);  // text font
	m_lives.setCharacterSize(24); //text size
	m_lives.setFillColor(sf::Color::White); // setting the color white for the text
	m_lives.setPosition(10, 70);  // position next to the score and message

	m_enemiesKilled.setFont(m_font);  // set the font for the text
	m_enemiesKilled.setCharacterSize(24); // set the text size
	m_enemiesKilled.setFillColor(sf::Color::White); // set the text colour
	m_enemiesKilled.setPosition(10, 100);  // its position on the screen
	//int to string

	setUpAA();
	setUpRR();
	loadBackground();
}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();
			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		myPlayer.moveLeft(); // calling move left function
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myPlayer.moveRight(); // calling moveRight function
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		myPlayer.moveUp(); // calling move up function
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myPlayer.moveDown(); // calling move down function
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		playerBullet.shootBulletUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		playerBullet.shootBulletLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		playerBullet.shootBulletdown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		playerBullet.shootBulletRight();
	}


	// update any game variables here 
	//bullet move
	playerBullet.bulletMove();
	//AA move
	arrayAA[0].moveAA();
	arrayAA[1].moveAA();
	arrayAA[2].moveAA();
	//AA boundry checking
	arrayAA[0].checkBoundry(arrayAA[0].getEnemyBody().getPosition());
	arrayAA[1].checkBoundry(arrayAA[1].getEnemyBody().getPosition());
	arrayAA[2].checkBoundry(arrayAA[2].getEnemyBody().getPosition());
	//RR movement
	arrayRR[0].moveRR(myPlayer.getBody().getPosition());
	arrayRR[1].moveRR(myPlayer.getBody().getPosition());
	//RR check boundry
	arrayRR[0].checkBoundryRR(arrayRR[0].getRRbody().getPosition());
	arrayRR[1].checkBoundryRR(arrayRR[1].getRRbody().getPosition());
	//ENEMY AND BULLET COLLISION FOR AA
	for (int counter = 0; counter < MAXAA; counter++)
	{
		if (playerBullet.boundingBox().intersects(arrayAA[counter].AAboundingBox()))
		{
			arrayAA[counter].setPositionAA();
			enemiesKilled = enemiesKilled + 1;
			gameScore = gameScore + 100;
			playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		}
	}
	//ENEMY AND BULLET COLLISION FOR RR
	for (int index = 0; index < MAXRR; index++)
	{
		if (playerBullet.boundingBox().intersects(arrayRR[index].getBoundingBoxRR()))
		{
			arrayRR[index].setPositionRR();
			enemiesKilled = enemiesKilled+ 1;
			gameScore = gameScore + 200;
			playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
		}
	}
	//PLAYER COLLISION DETECTION
	collisionDetection();
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	m_message.setString("Welcome to Liam's Game");
	m_score.setString("Score: " + std::to_string(gameScore));
	m_lives.setString("Lives: " );
	m_enemiesKilled.setString("Enemies Killed: " + std::to_string(enemiesKilled));
	window.draw(BGSprite); // draw the Sprite for background
	window.draw(m_score); // write score to the screen
	window.draw(m_lives);
	window.draw(m_enemiesKilled);
	window.draw(m_message);  // write message to the screen
	window.draw(m_healthBar);// health bar for player
	window.draw(myPlayer.getBody()); // draw the player character
	window.draw(playerBullet.getBulletBody());

	for (int count = 0; count < MAXRR; count++)
	{
		window.draw(arrayRR[count].getRRbody());
	}
	for (int plus = 0; plus < MAXAA; plus++)
	{
		window.draw(arrayAA[plus].getEnemyBody());
	}
	window.display();
}

void Game::loadBackground()
{
	if (!BGTexture.loadFromFile("ASSETS\\SPRITES\\floor.png"))
	{
		std::cout << "error loading the background image" << std::endl; // error message if background fails
	}
	BGTexture.setRepeated(true); // always showing
	BGSprite.setTexture(BGTexture); // setTexture and Sprite together
	BGSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Game::setUpAA() // set up positions
{
		arrayAA[0].setPositionAA(300, 300);
		arrayAA[1].setPositionAA(480, 100);
		arrayAA[2].setPositionAA(1400, 250);	
}

void Game::setUpRR() // set up RR Positions
{
		arrayRR[0].setPositionRR(400, 400);
		arrayRR[1].setPositionRR(600, 150);
}

void Game::collisionDetection()
{
	for (int plus = 0; plus < MAXAA; plus++)
	{
		if (myPlayer.playerBoundingBox().intersects(arrayAA[plus].AAboundingBox()))
		{
			myPlayer.setPosition();
		}
	}

	for (int add = 0; add < MAXRR; add++)
	{
		if (myPlayer.playerBoundingBox().intersects(arrayRR[add].getBoundingBoxRR()))
		{
			myPlayer.setPosition();
		}
	}
}

