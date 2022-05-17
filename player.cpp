#include "player.hpp"



Player::Player(int health, sf::Vector2f position, float speed) : Character(){
  _health = health;
  _maxHealth = health;
  _position = position;

  _type="Player";

  _hitbox = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _hitbox.setPosition(position);
  _hitbox.setFillColor(sf::Color::Red);

  _shape = sf::RectangleShape(sf::Vector2f(50.0f,80.0f));
  _shape.setPosition(position);


  this->setHealthBar();
  _speed = speed;

  _shootDelay=true;
}


void Player::move(sf::Event& event, sf::Time& dt, Map& map){
  switch(event.type){
    case sf::Event::KeyPressed:
      if(event.key.code == sf::Keyboard::Key::Z) up=true;
      if(event.key.code == sf::Keyboard::Key::S) down=true;
      if(event.key.code == sf::Keyboard::Key::D) right=true;
      if(event.key.code == sf::Keyboard::Key::Q) left=true;
      if(event.key.code == sf::Keyboard::Key::E) _shoot=true;
      break;

    case sf::Event::KeyReleased:
      if(event.key.code == sf::Keyboard::Key::Z) up = false;
      if(event.key.code == sf::Keyboard::Key::S) down = false;
      if(event.key.code == sf::Keyboard::Key::D) right = false;
      if(event.key.code == sf::Keyboard::Key::Q) left = false;
      if(event.key.code == sf::Keyboard::Key::E) _shoot = false ;
      break;
  }

  if(_shoot && _shootDelay){
    shoot(map);
    shootDelay();
  }

  _velocity.x = 0.f;
  _velocity.y = 0.f;

  if (up && _position.y>=0){
    //if the player is mooving along 2 directions divide the speed by sqrt(2) to stay at the same speed
    if (right || left) _velocity.y += -_speed*dt.asSeconds()/sqrt(2);
    else _velocity.y += -_speed*dt.asSeconds();
  }
  if (down && _position.y< 600 - _hitbox.getSize().y){
    if (right || left) _velocity.y += _speed*dt.asSeconds()/sqrt(2);
    else _velocity.y += _speed*dt.asSeconds();
  }
  if (right && _position.x<800 - _hitbox.getSize().x){
    if (up || down) _velocity.x += _speed*dt.asSeconds()/sqrt(2);
    else _velocity.x += _speed*dt.asSeconds();
  }
  if (left && _position.x>0){
    if (up || down) _velocity.x += -_speed*dt.asSeconds()/sqrt(2);
    else _velocity.x += -_speed*dt.asSeconds();
  }




  //_hitbox.move(_velocity.x, _velocity.y);
  _position += _velocity;
  checkCollision(map);
  updatePosition();
}

void Player::shoot(Map& map){
  map.addBullet(getCenter());
}
