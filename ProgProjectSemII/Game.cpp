// Name: Liam Treacy
// Login: started MARCH 20th 2024 9:08am
// Date: 20/03/24
// Approximate time taken: Currently: 23 hours (i think)
//---------------------------------------------------------------------------
// Project description: Magnet Misadventure is a small shooting game created by me,
// In this game you are a magnet who is trying to destroy all the rubbish that is trying to kill you, you shoot with W S A D and MOVE 
// with Up, Down, Left and Right, the game ends when you are out of health and lives, you are trying to get as many enemies killed as you can 
// and gain as high a score as you possibly can.
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
#include "gameOver.h" //gameOverheader


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

	m_healthBar.setFillColor(sf::Color::Green);
	m_healthBar.setSize(sf::Vector2f{100.0f, 50.0f });
	m_healthBar.setPosition(1400.0f, 0.0f);

	m_lives.setFont(m_font);  // text font
	m_lives.setCharacterSize(24); //text size
	m_lives.setFillColor(sf::Color::White); // setting the color white for the text
	m_lives.setPosition(10, 70);  // position next to the score and message

	m_enemiesKilled.setFont(m_font);  // set the font for the text
	m_enemiesKilled.setCharacterSize(24); // set the text size
	m_enemiesKilled.setFillColor(sf::Color::Yellow); // set the text colour
	m_enemiesKilled.setPosition(10, 100);  // its position on the screen
	m_enemiesKilled.setOutlineColor(sf::Color::Black);

	Rank.setFont(m_font);  // set the font for the text
	Rank.setCharacterSize(24); // set the text size
	Rank.setFillColor(sf::Color::Yellow); // set the text colour
	Rank.setPosition(1410, 730);  // its position on the screen

	playerRank.setFont(m_font);  // set the font for the text
	playerRank.setCharacterSize(24); // set the text size
	playerRank.setFillColor(sf::Color::Yellow); // set the text colour
	playerRank.setPosition(1470, 730);  // its position on the screen

	setUpAA();
	setUpRR();
	setUpCC();
	loadBackground();
	setUpAudio();
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
	if (gameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			reset();
		}
	}
	else
	{
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
		//CC Movement
		CCenemy.moveCC();
		//CC Boundry Checking
		CCenemy.checkBoundryCC(CCenemy.getCCBody().getPosition());
		//ENEMY AND BULLET COLLISION FOR AA
		for (int counter = 0; counter < MAXAA; counter++)
		{
			if (playerBullet.boundingBox().intersects(arrayAA[counter].AAboundingBox()) && playerBullet.isActive())
			{
				arrayAA[counter].setPositionAA();
				enemiesKilled = enemiesKilled + 1;
				gameScore = gameScore + 100;
				playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
				playerBullet.setNotActive();
				enemyHurt.setBuffer(enemyHurtBuffer);
				enemyHurt.play();
				enemyHurt.setLoop(false);
				enemyHurt.setPitch(1.0f);
			}
		}
		//ENEMY AND BULLET COLLISION FOR RR
		for (int index = 0; index < MAXRR; index++)
		{
			if (playerBullet.boundingBox().intersects(arrayRR[index].getBoundingBoxRR()) && playerBullet.isActive())
			{
				arrayRR[0].setPositionRR(1110, 0);
				arrayRR[1].setPositionRR(500, 200);
				enemiesKilled = enemiesKilled + 1;
				gameScore = gameScore + 200;
				playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
				playerBullet.setNotActive();
				enemyHurt.setBuffer(enemyHurtBuffer);
				enemyHurt.play();
				enemyHurt.setLoop(false);
				enemyHurt.setPitch(1.0f);
			}
		}
		//ENEMY AND BULLET COLLISION FOR cc
		if (playerBullet.boundingBox().intersects(CCenemy.boundBoxCC()) && playerBullet.isActive())
		{
			CCenemy.setPositionCC(400, 400);
			enemiesKilled = enemiesKilled + 1;
			gameScore = gameScore + 250;
			playerBullet.setPositionBullet(myPlayer.getBody().getPosition());
			playerBullet.setNotActive();
			enemyHurt.setBuffer(enemyHurtBuffer);
			enemyHurt.play();
			enemyHurt.setLoop(false);
			enemyHurt.setPitch(1.0f);
		}

		//PLAYER COLLISION DETECTION
		collisionDetection();
		//update Health Bar
		if (life == 3 || life == 2)
		{
			m_healthBar.setFillColor(sf::Color::Yellow);
		}

		if (life == 1)
		{
			m_healthBar.setFillColor(sf::Color::Red);
		}

		if (life == 0)
		{
			gameOver = true;
			death.setBuffer(deathBuffer);
			death.play();
			death.setPitch(1.0f);
			death.setLoop(false);
		}
		//rank system
		if (gameScore <= 200)
		{
			playerRank.setString("F");
		}

		if (gameScore >= 750)
		{
			playerRank.setString("E");
		}

		if (gameScore >= 2100)
		{
			playerRank.setString("D");
		}

		if (gameScore >= 4500)
		{
			playerRank.setString("C");
		}

		if (gameScore >= 7000)
		{
			playerRank.setString("B");
		}

		if (gameScore >= 9325)
		{
			playerRank.setString("A");
		}

		if (gameScore >= 12000)
		{
			playerRank.setString("S");
		}

		if (gameScore >= 20000)
		{
			playerRank.setString("S+");
		}
		// enemy speed up functions
		if (gameScore >= 3000)
		{
			arrayAA[0].speedUp();
			arrayAA[1].speedUp();
			arrayAA[2].speedUp();
		}

		if (gameScore >= 4500)
		{
			CCenemy.speedUpCC();
		}

		if (gameScore >= 7000)
		{
			arrayAA[0].speedEvenFaster();
			arrayAA[1].speedEvenFaster();
			arrayAA[2].speedEvenFaster();
		}

		if (gameScore >= 8500)
		{
			CCenemy.maxSpeedCC();
		}
	}
	if (gameTime % 50 == 0)
	{
		CCenemy.changeDirection();
	}
	gameTime++;
}
void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();
	if (gameOver)
	{
		m_score.setString("Your Final Score: " + std::to_string(gameScore));
		m_enemiesKilled.setString("The number of Enemies you killed: " + std::to_string(enemiesKilled));
		m_message.setString("Press R to reset and have more fun");
		gameOverScreen.draw(window);
		window.draw(m_score);
		window.draw(m_enemiesKilled);
		window.draw(m_message);
		window.draw(Rank);
		window.draw(playerRank);
	}
	else
	{
		m_message.setString("Welcome to Liam's Game");
		m_score.setString("Score: " + std::to_string(gameScore));
		m_lives.setString("Health: " + std::to_string(life));
		m_enemiesKilled.setString("Enemies Killed: " + std::to_string(enemiesKilled));
		Rank.setString("Rank: ");
		window.draw(BGSprite); // draw the Sprite for background
		window.draw(m_score); // write score to the screen
		window.draw(m_lives); // health count
		window.draw(Rank); // rank text
		window.draw(playerRank); // letter rank for player ranging from F - S+
		window.draw(m_enemiesKilled); // how many enemies were killed
		window.draw(m_message);  // write message to the screen
		window.draw(CCenemy.getCCBody()); // draw enemy CC, who is a ghost
		window.draw(m_healthBar);// health bar for player
		window.draw(myPlayer.getBody()); // draw the player character

		if (playerBullet.isActive())
		{
			window.draw(playerBullet.getBulletBody());
		}

		for (int count = 0; count < MAXRR; count++)
		{
			window.draw(arrayRR[count].getRRbody());
		}
		for (int plus = 0; plus < MAXAA; plus++)
		{
			window.draw(arrayAA[plus].getEnemyBody());
		}

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
		arrayAA[0].setPositionAA(600, 200);
		arrayAA[1].setPositionAA(780, 100);
		arrayAA[2].setPositionAA(1400, 150);
}

void Game::setUpRR() // set up RR Positions
{
		arrayRR[0].setPositionRR(100, 100);
		arrayRR[1].setPositionRR(600, 150);
}

void Game::setUpCC()
{
	CCenemy.setPositionCC(650, 102);
}


void Game::collisionDetection()
{
	for (int plus = 0; plus < MAXAA; plus++)
	{
		if (myPlayer.playerBoundingBox().intersects(arrayAA[plus].AAboundingBox()))
		{
			myPlayer.setPosition();
			life--;
			gameScore = gameScore - 100;
			playerHurt.setBuffer(playerHurtBuffer);
			playerHurt.play();
			playerHurt.setLoop(false);
			playerHurt.setPitch(1.0f);
		}
	}
	for (int add = 0; add < MAXRR; add++)
	{
		if (myPlayer.playerBoundingBox().intersects(arrayRR[add].getBoundingBoxRR()))
		{
			myPlayer.setPosition();
			life--;
			gameScore = gameScore - 100;
			arrayRR[0].setPositionRR(800, 700);
			arrayRR[1].setPositionRR(1000, 50);
			playerHurt.setBuffer(playerHurtBuffer);
			playerHurt.play();
			playerHurt.setLoop(false);
			playerHurt.setPitch(1.0f);
		}
	}
	if (myPlayer.playerBoundingBox().intersects(CCenemy.boundBoxCC()))
	{
		myPlayer.setPosition();
		life--;
		gameScore = gameScore - 100;
		playerHurt.setBuffer(playerHurtBuffer);
		playerHurt.play();
		playerHurt.setLoop(false);
		playerHurt.setPitch(1.0f);
	}
}

void Game::setUpAudio()
{
	if (!deathBuffer.loadFromFile("ASSETS\\AUDIO\\death.wav"))
	{
		std::cout << "ERROR LOADING THE DEATH SOUND" << std::endl;
	}

	if (!enemyHurtBuffer.loadFromFile("ASSETS\\AUDIO\\hurt.wav"))
	{
		std::cout << "ERROR LOADING THE AUDIO FOR ENEMY HURT" << std::endl;
	}

	if (!playerHurtBuffer.loadFromFile("ASSETS\\AUDIO\\glassBreak.wav"))
	{
		std::cout << "error loading the player hurt audio " << std::endl;
	}
}


void Game::reset() // don e with some assistance from Pete
{
	gameOver = false;
	life = 5;
	gameScore = 0;
	m_score.setString("Score: " + std::to_string(gameScore));
	enemiesKilled = 0;
	myPlayer.setPosition(400.0f, 400.0f);
	std::cout << "reset" << std::endl;
	setUpAA();
	setUpRR();
	playerBullet.setPositionBullet(sf::Vector2f{ 400.0f,400.0f });
	m_healthBar.setFillColor(sf::Color::Green);
}
