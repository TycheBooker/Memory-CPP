#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TableRotation.h"

class TableBorder
{
public:
	TableBorder(std::vector<Player *> players);
	~TableBorder();

	void renderTableBorder(sf::RenderWindow & window);
	void callNextPlayer();
	void score();
private:
	static const std::vector<sf::Vector2f> playerPositions;
	static const std::vector<float> playerRotations;

	void positionPlayers();
	void setPlayerLocation(sf::Text & playerTag, int position);

	sf::View tableBorderView;
	std::vector<sf::RectangleShape> tableBorderBackground;
	void createBackground();

	void renderBackground(sf::RenderWindow & window);
	void renderPlayers(sf::RenderWindow & window);

	std::vector<Player *> players;
	unsigned currentPlayer;

	TableRotation * tableRotation;
};