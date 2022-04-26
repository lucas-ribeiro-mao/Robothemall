#include "player.hpp"

Player::Player(int playerID,int health, sf::Vector2f position, float speed){
  _playerID = playerID;
  _health = health;
  _position = position;
  _hitbox = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Red);

  _speed = speed;
}


void Player::move(sf::Event event, sf::Time dt){
  switch(event.type){
    case sf::Event::KeyPressed:
      if(event.key.code == sf::Keyboard::Key::Z) up=true;
      if(event.key.code == sf::Keyboard::Key::S) down=true;
      if(event.key.code == sf::Keyboard::Key::D) right=true;
      if(event.key.code == sf::Keyboard::Key::Q) left=true;
      break;

    case sf::Event::KeyReleased:
      if(event.key.code == sf::Keyboard::Key::Z) up = false;
      if(event.key.code == sf::Keyboard::Key::S) down = false;
      if(event.key.code == sf::Keyboard::Key::D) right = false;
      if(event.key.code == sf::Keyboard::Key::Q) left = false;
      break;
  }

  if (up){
    _hitbox.move(0.0f, -_speed*dt.asSeconds());
    _shape.move(0.0f, -_speed*dt.asSeconds());
  }
  if (down){
    _hitbox.move(0.0f, _speed*dt.asSeconds());
    _shape.move(0.0f, _speed*dt.asSeconds());
  }
  if (right){
    _hitbox.move(_speed*dt.asSeconds(), 0.0f);
    _shape.move(_speed*dt.asSeconds(), 0.0f);
  }
  if (left){
    _hitbox.move(-_speed*dt.asSeconds(), 0.0f);
    _shape.move(-_speed*dt.asSeconds(), 0.0f);
  }
}
