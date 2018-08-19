#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "GameScreen.h"
#include "EndScreen.h"
#include "Card.h"
#include "Player.h"
#include "SetTimeout.h"

class GameBoard :
	public GameScreen
{
public:
	GameBoard(StateManager * stateManager);
	~GameBoard();

	void renderScreen(sf::RenderWindow & window);
	void updateScreen(sf::Time deltaTime);
	void handleMouseClick(sf::Vector2f mousePosition);
private:
	std::vector<Card*> deck;
	std::vector<Card*> revealedCards;
	std::vector<Card*> solvedCards;
	std::vector<Card*> createDeck(sf::Vector2u boardSize);

	std::vector<Player *> players;
	unsigned currentPlayer;
	static std::vector<sf::Vector2f> playerPositions;
	static std::vector<float> playerRotations;
	void positionPlayers();
	void callNextPlayer();

	void renderPlayingField(sf::RenderWindow & window);
	void renderDeck(sf::RenderWindow & window);
	void updateDeck(sf::Time deltaTime);
	void renderPlayers(sf::RenderWindow & window);

	Card* cardClicked(sf::Vector2f mousePosition);
	void handleCardClick(Card * clickedCard);
	void resolvePair(bool isPair);
	void finishGame();

	SetTimeout * resolveTimeout;
	sf::RectangleShape playingFieldBackground;
	sf::View playingField;
	sf::View playersHUD;
};