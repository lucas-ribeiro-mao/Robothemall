# include "foes.hpp"

Foes::Foes( int health, sf::Vector2f position, float speed, sf::Texture* texture) : Character(){
  _health=health;
  _maxHealth=health;
  _position = position;
  _type = "Foes";

  _hitbox = sf::RectangleShape(sf::Vector2f(30.0f,30.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(32.0f,32.0f));
  _shape.setPosition(position);
  _shape.setTexture(texture);

  _textureSize = texture->getSize();
  _textureSize.x /= 12;
  _textureSize.y /= 8;
  _shape.setTextureRect(sf::IntRect(_textureSize.x * 7,_textureSize.y * 0, _textureSize.x, _textureSize.y));



  this->setHealthBar();
  _speed = speed;

  swiftnessX = 0;
  swiftnessY = 0;
}

void Foes::move(sf::Event& event, sf::Time& dt, Map& map){
  float distj1,distj2;
  float directionX, directionY;

  // KNOWN AS PLAYER
  // TO IMPROVE FOR REAL
  if(map.getPlayerMap().size() > 0){


    //load the players from the map and go towards the clothest
    Player* j1 = (map.getPlayerMap().front());
    Player* j2 = (map.getPlayerMap().back());

    float diffPlay1X = j1->getCenter().x-this->getCenter().x;
    float diffPlay1Y = j1->getCenter().y-this->getCenter().y;

    float diffPlay2X = j2->getCenter().x-this->getCenter().x;
    float diffPlay2Y = j2->getCenter().y-this->getCenter().y;

    distj1=sqrt(pow(diffPlay1X,2)+pow(diffPlay1Y,2));
    distj2=sqrt(pow(diffPlay2X,2)+pow(diffPlay2Y,2));

    if(distj1<distj2){
      directionX = diffPlay1X;
      directionY = diffPlay1Y;
    }

    else {
      directionX = diffPlay2X;
      directionY = diffPlay2Y;
    }


    // in order to smoothen the deplacement, the foes mooves with an increasing acceleration
    float _acceleration=5.0;
    if(directionX>0 && swiftnessX<_speed){ swiftnessX+=_acceleration;}
    else if(directionX<0 && swiftnessX>-_speed){ swiftnessX-=_acceleration;}


    if(directionY>0 && swiftnessY<_speed){ swiftnessY+=_acceleration;}
    else if(directionY<0 && swiftnessY>-_speed){ swiftnessY-=_acceleration;}



    _velocity.x = swiftnessX*dt.asSeconds();
    _velocity.y = swiftnessY*dt.asSeconds();

    //set the sprite facing the fastest linear deplacement
    if     (_velocity.y > 0 && abs(_velocity.y) > abs(_velocity.x))
      _shape.setTextureRect(sf::IntRect(_textureSize.x * 7,_textureSize.y * 0, _textureSize.x, _textureSize.y));
    else if(_velocity.y < 0 && abs(_velocity.y) > abs(_velocity.x))
      _shape.setTextureRect(sf::IntRect(_textureSize.x * 7,_textureSize.y * 3, _textureSize.x, _textureSize.y));
    else if(_velocity.x > 0 && abs(_velocity.y) < abs(_velocity.x))
      _shape.setTextureRect(sf::IntRect(_textureSize.x * 7,_textureSize.y * 2, _textureSize.x, _textureSize.y));
    else if(_velocity.x < 0 && abs(_velocity.y) < abs(_velocity.x))
      _shape.setTextureRect(sf::IntRect(_textureSize.x * 7,_textureSize.y * 1, _textureSize.x, _textureSize.y));


  //check the X position
    _position+=_velocity;
  }
  checkCollision(map);
  updatePosition();

}
