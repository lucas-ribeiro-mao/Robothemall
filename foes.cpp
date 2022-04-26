# include "foes.hpp"

Foes::Foes( int health, sf::Vector2f position, float speed) : Character(){
  _health=health;
  _position = position;
  _hitbox = sf::RectangleShape(sf::Vector2f(30.0f,30.0f));
  _hitbox.setPosition(position);

  _shape = sf::RectangleShape(sf::Vector2f(30.0f,30.0f));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Green);

  _speed = speed;
}

void Foes::move(Player j1, sf::Time dt){
  float distj1,distj2;
  float directionX, directionY;

  distj1=sqrt(pow(j1.getX(),2)+pow(j1.getY(),2));
  //distj2=sqrt(pow(j2.getX(),2)+pow(j2.getY(),2));

  directionX = j1.getX()-this->getX();
  directionY = j1.getY()-this->getY();

/*
  if(distj1<distj2){
    directionX = j1.getX()-this->getX();
    directionY = j1.getY()-this->getY();
  }

  else {
    directionX = j2.getX()-this->getX();
    directionY = j2.getY()-this->getY();
  }
*/
  _position.x+=_speed*dt.asSeconds()*directionX;
  _position.y+=_speed*dt.asSeconds()*directionY;
  _hitbox.move(_speed*dt.asSeconds()*directionX, _speed*dt.asSeconds()*directionY);
  _shape.move(_speed*dt.asSeconds()*directionX, _speed*dt.asSeconds()*directionY);
}
