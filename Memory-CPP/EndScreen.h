#pragma once
#include "GameScreen.h"
#include "StartScreen.h"
#include "Player.h"

class EndScreen :
	public GameScreen
{
public:
	EndScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings);
	~EndScreen();

	void renderScreen(sf::RenderWindow & window);
	void updateScreen(sf::Time deltaTime);
	void handleEnterPressed();
	void setPlayers(std::vector<Player *> players);
private:
	void renderPlayerList(sf::RenderWindow & window);
	void renderPlayAgainButton(sf::RenderWindow & window);
	void displayPlayerScores();
	void sortPlayers();
	void setWinner();
	void positionTags();
	static bool sortByScore(const Player * firstPlayer, const Player * const secondPlayer);
};

