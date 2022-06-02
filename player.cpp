#include "player.hpp"


Player::Player(int health, sf::Vector2f position, float speed, int id, sf::Texture* texture) : Character(){
  _health = health;
  _maxHealth = health;
  _position = position;


  up = false;
  down = false;
  right = false;
  left = false;
  _shoot = false;

  _type="Player";

  _hitbox = sf::RectangleShape(sf::Vector2f(24.0f,30.0f));
  _hitbox.setPosition(position);
  _hitbox.setFillColor(sf::Color::Red);

  _shape = sf::RectangleShape(sf::Vector2f(32.0f,32.0f));
  _shape.setPosition(position);
  _shape.setTexture(texture);

  _textureSize = texture->getSize();
  _textureSize.x /= 12;
  _textureSize.y /= 8;

  this->setHealthBar();
  _speed = speed;

  _shootDelay=true;
  _isInvicible=false;

  gettimeofday(&previousShot, nullptr);
  gettimeofday(&prevInvState, nullptr);

  _shootRate = SHOOTRATE;

  if (id == 1){
    command4Direction.push_back(sf::Keyboard::Key::Z);
    command4Direction.push_back(sf::Keyboard::Key::S);
    command4Direction.push_back(sf::Keyboard::Key::D);
    command4Direction.push_back(sf::Keyboard::Key::Q);
    command4Direction.push_back(sf::Keyboard::Key::Space);
    _placeTexture.x=0;
    _placeTexture.y=0;
  }
  if (id == 2){
    command4Direction.push_back(sf::Keyboard::Key::I);
    command4Direction.push_back(sf::Keyboard::Key::K);
    command4Direction.push_back(sf::Keyboard::Key::L);
    command4Direction.push_back(sf::Keyboard::Key::J);
    command4Direction.push_back(sf::Keyboard::Key::Return);
    _placeTexture.x=0;
    _placeTexture.y=4;
  }

  _shape.setTextureRect(sf::IntRect(_textureSize.x * _placeTexture.x, _textureSize.y * _placeTexture.y, _textureSize.x, _textureSize.y));

}


void Player::move(sf::Event& event, sf::Time& dt, Map& map){
  int offsetTextureY = _placeTexture.y;
  switch(event.type){
    case sf::Event::KeyPressed:
      if(event.key.code == command4Direction[0]){
        up=true;
        offsetTextureY = _placeTexture.y + 3;
      }
      if(event.key.code == command4Direction[1]) {
        down=true;
        offsetTextureY = _placeTexture.y + 0;
      }
      if(event.key.code == command4Direction[2]) {
        right=true;
        offsetTextureY = _placeTexture.y + 2;
      }
      if(event.key.code == command4Direction[3]) {
        left=true;
        offsetTextureY = _placeTexture.y + 1;
      }
      if(event.key.code == command4Direction[4]) _shoot=true;

      // if the player changes direction, sprite displayed in the correct position
      _shape.setTextureRect(sf::IntRect(_textureSize.x * _placeTexture.x, _textureSize.y * offsetTextureY, _textureSize.x, _textureSize.y));
      break;

    case sf::Event::KeyReleased:
      if(event.key.code == command4Direction[0]) up = false;
      if(event.key.code == command4Direction[1]) down = false;
      if(event.key.code == command4Direction[2]) right = false;
      if(event.key.code == command4Direction[3]) left = false;
      if(event.key.code == command4Direction[4]) _shoot = false ;
      break;
    default :
      break;
  }


// if the player choode to shoot
  if(_shoot ){
    shootDelay();
    if (_shootDelay){
      shoot(map);
    }
  }

  _velocity.x = 0.f;
  _velocity.y = 0.f;


// the player can not go outside of the screen
  if (up && _position.y>=0){
    //if the player is mooving along 2 directions divide the speed by sqrt(2) to stay at the same speed
    if (right || left) _velocity.y += -_speed*dt.asSeconds()/sqrt(2);
    else _velocity.y += -_speed*dt.asSeconds();
  }
  if (down && _position.y< HEIGHT_WINDOW - _hitbox.getSize().y){
    if (right || left) _velocity.y += _speed*dt.asSeconds()/sqrt(2);
    else _velocity.y += _speed*dt.asSeconds();
  }
  if (right && _position.x< WIDTH_WINDOW - _hitbox.getSize().x){
    if (up || down) _velocity.x += _speed*dt.asSeconds()/sqrt(2);
    else _velocity.x += _speed*dt.asSeconds();
  }
  if (left && _position.x>0){
    if (up || down) _velocity.x += -_speed*dt.asSeconds()/sqrt(2);
    else _velocity.x += -_speed*dt.asSeconds();
  }


  _position += _velocity;
  checkCollision(map);
  updatePosition();
  invincibleDelay();
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


void Player::getHit(const float& dmg){
  // if player is damaged, become invincible
  if (!_isInvicible)
    {
      _health-=dmg;
      _isInvicible = true;
    }
}

void Player::invincibleDelay(){
  //if invincible and the delay as passed, become vincible
  if(_isInvicible){
    gettimeofday(&currInvState, nullptr);
    if (abs(prevInvState.tv_usec / 1000 - currInvState.tv_usec / 1000)>_invicibleDuration){
      prevInvState = currInvState;
      _isInvicible = false;
    }
  }
}
