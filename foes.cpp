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
  Player *j1 = (*map.getPlayerMap().begin());

  distj1=sqrt(pow(j1->getX(),2)+pow(j1->getY(),2));
  //distj2=sqrt(pow(j2.getX(),2)+pow(j2.getY(),2));
  sf::Vector2f playerCenter = j1->getCenter();
  sf::Vector2f foeCenter = this->getCenter();
  directionX = playerCenter.x - foeCenter.x;
  directionY = playerCenter.y - foeCenter.y;

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
/*
  if (directionX<125.0f && directionX>0) directionX=125.0f;
  else if (directionX>-125.0f && directionX<0) directionX=-125.0f;
  else if (directionY<125.0f && directionY>0) directionY=125.0f;
  else if (directionY>-125.0f && directionY<0) directionY=-125.0f;

  else if (directionX<-200.0f) directionX=-200.0f;
  else if (directionX>200.0f) directionX=200.0f;
  else if (directionY<-200.0f) directionY=-200.0f;
  else if (directionY>200.0f) directionY=200.0f;
*/



  float _acceleration=0.2f;
  if(directionX>0 && swiftnessX<_speed){ swiftnessX+=_acceleration;}
  else if(directionX<0 && swiftnessX>-_speed){ swiftnessX-=_acceleration;}


  if(directionY>0 && swiftnessY<_speed){ swiftnessY+=_acceleration;}
  else if(directionY<0 && swiftnessY>-_speed){ swiftnessY-=_acceleration;}



  _prevPosition=_position;

  float deltaX = swiftnessX*dt.asSeconds();
  float deltaY = swiftnessY*dt.asSeconds();

//check the X position

  sf::Vector2f posBreak;
  sf::Vector2f sizeBreak;

  _position.x+=deltaX;
  _position.y+=deltaY;
  _hitbox.setPosition(_position);
  bool canGo=true;
  for (auto player : map.getPlayerMap()){
    if ((*this).getID()!=player->getID() && canGo){
      switch((*this).collision(*player)){
        case 1 :
          canGo=false;
          _position.x=player->getPos().x + player->getHitbox().getSize().x;
          break;
        case 2 :
          canGo=false;
          _position.x=player->getPos().x - _hitbox.getSize().x;
          break;
        case 3 :
          canGo=false;
          _position.y=player->getPos().y + player->getHitbox().getSize().y;
          break;
        case 4 :
          canGo=false;
          _position.y=player->getPos().y - _hitbox.getSize().y;
          break;
      }
    }
  }

  if (canGo){
    for (auto foes : map.getFoesMap()){
      if ((*this).getID()!=foes->getID() && canGo){
        switch((*this).collision(*foes)){
          case 1 :
            canGo=false;
            _position.x=foes->getPos().x + foes->getHitbox().getSize().x;
            break;
          case 2 :
            canGo=false;
            _position.x=foes->getPos().x - _hitbox.getSize().x;
            break;
          case 3 :
            canGo=false;
            _position.y=foes->getPos().y + foes->getHitbox().getSize().y;
            break;
          case 4 :
            canGo=false;
            _position.y=foes->getPos().y - _hitbox.getSize().y;
            break;
        }
      }
    }
  }




  updatePosition();

}
