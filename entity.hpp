#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace std;

class Renderer;
class Map;

class Entity {
  protected :
    sf::Vector2f _position;
    sf::RectangleShape _hitbox;
    sf::RectangleShape _shape;
    std::string _type;

    int _ID;
    static int serialID;

  public :
    Entity(){_ID = nextID();}

    virtual void display(Renderer& r) const =0;

    int collision(const Entity& other){
      sf::FloatRect thisBox = this->getHitbox().getGlobalBounds();
      sf::FloatRect otherBox = other.getHitbox().getGlobalBounds();

      sf::Vector2f thisHitbox = this->getHitbox().getSize();
      sf::Vector2f otherHitbox = other.getHitbox().getSize();

      sf::Vector2f thisPos = this->getPos();
      sf::Vector2f otherPos = other.getPos();

      if (thisBox.intersects(otherBox)){
        //right collision
        if(thisPos.x<otherPos.x
          && thisPos.x + thisHitbox.x < otherPos.x + otherHitbox.x
          && thisPos.y < otherPos.y + otherHitbox.y
          && thisPos.y + thisHitbox.y > otherPos.y
        ){
          return 2;
        }
        //left collision
        else if(thisPos.x > otherPos.x
          && thisPos.x + thisHitbox.x > otherPos.x + otherHitbox.x
          && thisPos.y < otherPos.y + otherHitbox.y
          && thisPos.y + thisHitbox.y > otherPos.y
        ){
          return 1;
        }


        //Down collision
        if(thisPos.y<otherPos.y
          && thisPos.y + thisHitbox.y < otherPos.y + otherHitbox.y
          && thisPos.x < otherPos.x + otherHitbox.x
          && thisPos.x + thisHitbox.x > otherPos.x
        ){
          return 4;
        }
        //Up collision
        else if(thisPos.y > otherPos.y
          && thisPos.y + thisHitbox.y > otherPos.y + otherHitbox.y
          && thisPos.x < otherPos.x + otherHitbox.x
          && thisPos.x + thisHitbox.x > otherPos.x
        ){
          return 3;
        }
      }
      return 0;
    }

    virtual void move(sf::Event& event, sf::Time& dt, Map& map) =0;

    static int nextID() { serialID++; return serialID; }

    // ACCESSEURS
    const float& getX() const { return _position.x; }
    float& getX() { return _position.x; }
    const float& getY() const { return _position.y; }
    float& getY() { return _position.y; }
    const sf::Vector2f& getPos() const { return _position; }
    sf::Vector2f& getPos() { return _position; }

    sf::Vector2f getCenter(){ return sf::Vector2f(_position.x+_shape.getSize().x/2,_position.y+_shape.getSize().y/2);}

    const sf::RectangleShape& getShape() const { return _shape; }
    sf::RectangleShape& getShape() { return _shape; }

    const sf::RectangleShape& getHitbox() const { return _hitbox; }
    sf::RectangleShape& getHitbox() { return _hitbox; }

    const std::string& getType() const { return _type; }
    const int& getID() const { return _ID; }

    //OPERATEURS
    bool operator==(const Entity& e) const{ return _position.x==e.getX() && _position.y==e.getY() && _shape.getSize()==e.getShape().getSize();};
};

#endif
