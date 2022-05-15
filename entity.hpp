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
    sf::Vector2f _velocity;
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

      sf::FloatRect nextPosition;
      nextPosition = thisBox;
      nextPosition.left += _velocity.x;
      nextPosition.top += _velocity.y;


      int answer =0;

      if (nextPosition.intersects(otherBox)){
        //right collision
        if(thisBox.left < otherBox.left
          && thisBox.left + thisBox.width < otherBox.left + otherBox.width
          && thisBox.top < otherBox.top + otherBox.height
          && thisBox.top + thisBox.height > otherBox.top
        ){
          answer+= 2;
        }
        //left collision
        else if(thisBox.left > otherBox.left
          && thisBox.left + thisBox.width > otherBox.left + otherBox.width
          && thisBox.top < otherBox.top + otherBox.height
          && thisBox.top + thisBox.height > otherBox.top
        ){
          answer+= 1;
        }

        //Down collision
        if(thisBox.top < otherBox.top
          && thisBox.top + thisBox.height < otherBox.top + otherBox.height
          && thisBox.left < otherBox.left + otherBox.width
          && thisBox.left + thisBox.width > otherBox.left
        ){
          answer+= 20;
        }
        //Up collision
        else if(thisBox.top > otherBox.top
          && thisBox.top + thisBox.height > otherBox.top + otherBox.height
          && thisBox.left < otherBox.left + otherBox.width
          && thisBox.left + thisBox.width > otherBox.left
        ){
          answer+= 10;
        }
      }
      return answer;
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
