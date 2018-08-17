#include "stdafx.h"
#include "Widget.h"

Widget::Widget()
{
}

Widget::~Widget()
{
}

void Widget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
  for(size_t i = 0; i < components.size(); i++)
  {
    target.draw(*components[i], states);
  }
}

bool Widget::isClicked(sf::Vector2f mousePosition)
{
  for(size_t i = 0; i < components.size(); i++)
  {
    if (components[i]->isSelectable())
    {
      return components[i]->isClicked(mousePosition);
      // add transform?
    }
  }
}

void Widget::handleMouseClick(sf::Vector2f mousePosition)
{
  for(size_t i = 0; i < components.size(); i++)
  {
    if (components[i]->isSelectable() && components[i]->isClicked(mousePosition))
    {
      components[i]->handleMouseClick();
      // add transform?
    }
  }
}

void Widget::handleTextEntry(sf::Event::TextEvent textEntry)
{
  if (!supportsTextEntry)
  {
    return;
  }
}

void Widget::positionRow(std::vector<GUIComponent *> & widgetRow, sf::Vector2f startPosition)
{
  float rowWidth = startPosition.x;
  for(size_t i = 0; i < widgetRow.size(); i++)
  {
    widgetRow[i]->setPosition(rowWidth, startPosition.y);
    rowWidth += widgetRow[i]->getSize().x;
  }
}
