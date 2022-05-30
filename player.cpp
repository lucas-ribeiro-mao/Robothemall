#include "player.hpp"



Player::Player(int health, sf::Vector2f position, float speed, int id) : Character(){
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

  gettimeofday(&previousShot, nullptr);

  if (id == 1){
    command4Direction.push_back(sf::Keyboard::Key::Z);
    command4Direction.push_back(sf::Keyboard::Key::S);
    command4Direction.push_back(sf::Keyboard::Key::D);
    command4Direction.push_back(sf::Keyboard::Key::Q);
    command4Direction.push_back(sf::Keyboard::Key::E);
  }
  if (id == 2){
    command4Direction.push_back(sf::Keyboard::Key::I);
    command4Direction.push_back(sf::Keyboard::Key::K);
    command4Direction.push_back(sf::Keyboard::Key::L);
    command4Direction.push_back(sf::Keyboard::Key::J);
    command4Direction.push_back(sf::Keyboard::Key::O);
  }

}


void Player::move(sf::Event& event, sf::Time& dt, Map& map){
  switch(event.type){
    case sf::Event::KeyPressed:
      if(event.key.code == command4Direction[0]) up=true;
      if(event.key.code == command4Direction[1]) down=true;
      if(event.key.code == command4Direction[2]) right=true;
      if(event.key.code == command4Direction[3]) left=true;
      if(event.key.code == command4Direction[4]) _shoot=true;
      break;

    case sf::Event::KeyReleased:
      if(event.key.code == command4Direction[0]) up = false;
      if(event.key.code == command4Direction[1]) down = false;
      if(event.key.code == command4Direction[2]) right = false;
      if(event.key.code == command4Direction[3]) left = false;
      if(event.key.code == command4Direction[4]) _shoot = false ;
      break;
  }


  if(_shoot ){
    shootDelay();
    if (_shootDelay){
      shoot(map);}
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

void Player::shootDelay(){
  gettimeofday(&currentShot, nullptr);
  if (abs(previousShot.tv_usec / 1000 - currentShot.tv_usec / 1000)>200){
    previousShot = currentShot;
    _shootDelay = true;
  }
  else _shootDelay = false;
}
