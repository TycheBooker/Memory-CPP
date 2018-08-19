#include "GameScreen.h"
#include "AssetManager.h"

GameScreen::GameScreen()
{
}

GameScreen::GameScreen(StateManager * stateManager) :
	stateManager(stateManager)
{
}

GameScreen::~GameScreen()
{
}

sf::Sprite GameScreen::background(AssetManager::getInstance()->getTexture("Background(1024x768).png"));

void GameScreen::renderScreen(sf::RenderWindow & window)
{
	window.draw(background);
}

void GameScreen::handleMouseClick(sf::Vector2f mousePosition)
{
}

void GameScreen::handleTextEntry(sf::Event::TextEvent textEvent)
{
}

