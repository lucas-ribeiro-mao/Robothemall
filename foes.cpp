# include "foes.hpp"

Foes::Foes( int health, sf::Vector2f position, float speed) : Character(){
  _health=health;
  _maxHealth=health;
  _position = position;
  _type = "Foes";

  _hitbox = sf::RectangleShape(sf::Vector2f(30.0f,30.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(30.0f,30.0f));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Green);


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


    float _acceleration=0.2f;
    if(directionX>0 && swiftnessX<_speed){ swiftnessX+=_acceleration;}
    else if(directionX<0 && swiftnessX>-_speed){ swiftnessX-=_acceleration;}


    if(directionY>0 && swiftnessY<_speed){ swiftnessY+=_acceleration;}
    else if(directionY<0 && swiftnessY>-_speed){ swiftnessY-=_acceleration;}



    //_prevPosition=_position;

    _velocity.x = swiftnessX*dt.asSeconds();
    _velocity.y = swiftnessY*dt.asSeconds();

  //check the X position
    _position+=_velocity;
}
  checkCollision(map);
  updatePosition();
  //updateHealth();

}



void Foes::getHit(Bullet& bullet, Map& map){
  _health-=10;
}
