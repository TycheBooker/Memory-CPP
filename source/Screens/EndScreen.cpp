#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	players(stateManager->gameSettings->players),
	playAgainButton(new Button("Play again", std::bind(&EndScreen::restartGame, this)))
{
	playAgainButton->setPosition({ 400.f, 600.f });
	displayPlayerScores();
}

EndScreen::~EndScreen()
{
	delete playAgainButton;
}

void EndScreen::renderScreen(sf::RenderWindow & window)
{
	GameScreen::renderScreen(window);
	renderPlayerList(window);
	renderPlayAgainButton(window);
}

void EndScreen::updateScreen(sf::Time deltaTime)
{
	updatePlayerList(deltaTime);
}

void EndScreen::handleMouseClick(sf::Vector2f mousePosition)
{
	playAgainButton->handleMouseClick(mousePosition);
}


void EndScreen::displayPlayerScores()
{
	sortPlayers();
	setWinner();
	positionTags();
	fadeInPlayerList();
}

void EndScreen::sortPlayers()
{
	std::sort(players.begin(), players.end(), sortByScore);
}

bool EndScreen::sortByScore(const Player * firstPlayer, const Player * secondPlayer)
{
	return (firstPlayer->score > secondPlayer->score);
}

void EndScreen::setWinner()
{
	if (players.size() == 1)
	{
		return;
	}
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->playerTag.setCharacterSize(48);
		players[i]->playerScore.setCharacterSize(48);
		if (i + 1 < players.size() && players[i]->score > players[i + 1]->score)
		{
			break;
		}
	}
}

void EndScreen::positionTags()
{
	float playerListHeight = 100.f;
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->playerTag.setPosition(100.f, playerListHeight);
		players[i]->playerScore.setPosition(300.f, playerListHeight);
		playerListHeight += players[i]->playerTag.getCharacterSize() + 16.f;
	}
}

void EndScreen::fadeInPlayerList()
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->fadePlayer(true, Player::PlayerComponents::All);
	}
}

void EndScreen::renderPlayerList(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayer(window, Player::PlayerComponents::All);
	}
}

void EndScreen::renderPlayAgainButton(sf::RenderWindow & window)
{
	window.draw(*playAgainButton);
}

void EndScreen::updatePlayerList(sf::Time deltaTime)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->updatePlayer(deltaTime, Player::PlayerComponents::All);
	}
}

void EndScreen::restartGame()
{
	stateManager->clearSettings();
	stateManager->switchScreen(StateManager::Screen::StartScreen);
}