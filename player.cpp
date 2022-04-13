#include "player.hpp"

Player::Player(int playerID,int health, sf::Vector2f position){
  _playerID = playerID;
  _health = health;
  _position = position;
  _hitbox = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Red);
}
