#include "stdafx.h"
#include "Player.h"

Player::Player(std::string name) :
	name(name),
	score(0),
	playerTag(name, playerFont),
	playerScore("0", playerFont)
{
}

Player::~Player()
{
}

sf::Font & Player::playerFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");

void Player::renderPlayerTag(sf::RenderWindow & window)
{
	window.draw(playerTag);
}

void Player::renderPlayerScore(sf::RenderWindow & window)
{
	window.draw(playerScore);
}

void Player::increaseScore()
{
	score++;
	playerScore.setString(std::to_string(score));
}