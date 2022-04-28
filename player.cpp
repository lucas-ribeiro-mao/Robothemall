#include "player.hpp"



Player::Player(int health, sf::Vector2f position, float speed) : Character(){
  _health = health;
  _maxHealth=health;
  _position = position;



  _hitbox = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Red);

  this->setHealthBar();
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

// OPTIMISATION POSSIBLE SI TROP DE RETARD
  float pospresX = _position.x;
  float pospresY = _position.y;
  if (up && _position.y>=0){
    //if the player is mooving along 2 directions divide the speed by sqrt(2) to stay at the same speed
    if (right || left) _position.y += -_speed*dt.asSeconds()/sqrt(2);
    else _position.y += -_speed*dt.asSeconds();
  }
  if (down && _position.y< 600 - _shape.getSize().y){
    if (right || left) _position.y += _speed*dt.asSeconds()/sqrt(2);
    else _position.y += _speed*dt.asSeconds();
  }
  if (right && _position.x<800 - _shape.getSize().x){
    if (up || down) _position.x += _speed*dt.asSeconds()/sqrt(2);
    else _position.x += _speed*dt.asSeconds();
  }
  if (left && _position.x>0){
    if (up || down) _position.x += -_speed*dt.asSeconds()/sqrt(2);
    else _position.x += -_speed*dt.asSeconds();
  }

  healthBar[0].move(_position.x - pospresX, _position.y - pospresY);
  _hitbox.move(_position.x - pospresX, _position.y - pospresY);
  _shape.move(_position.x - pospresX, _position.y - pospresY);
}
