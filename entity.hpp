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
    //position of the entity in the map
    sf::Vector2f _position;
    // speed of the entity in the map
    sf::Vector2f _velocity;

    // Hitbox and shape of entity : The entity get hit on hitbox but only the shape is visible
    sf::RectangleShape _hitbox;
    sf::RectangleShape _shape;
    sf::Vector2u _textureSize;

    //type of the entity (Ex : Player)
    std::string _type;

    //unique ID for each entity
    int _ID;
    static int serialID;

  public :
    Entity(){_ID = nextID();}
    virtual ~Entity() = default;

    //display the entity
    virtual void display(Renderer& r) const =0;

    //Find if there is a collision between two entities : summ all of the numbers
    // 0 if not
    // 1 or 2 on the right or left side
    // 10 or 20 on the top or the bottom
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

    //Make the entity moove
    virtual void move(sf::Event& event, sf::Time& dt, Map& map) =0;

    //Select the ID of the entity
    static int nextID() { serialID++; return serialID; }

    // ACCESSEURS
    const float& getX() const { return _position.x; }
    float& getX() { return _position.x; }
    const float& getY() const { return _position.y; }
    float& getY() { return _position.y; }
    const sf::Vector2f& getPos() const { return _position; }
    sf::Vector2f& getPos() { return _position; }

    // return the center of the _shape
    const sf::Vector2f getCenter() const { return sf::Vector2f(_position.x+_shape.getSize().x/2,_position.y+_shape.getSize().y/2);}
    sf::Vector2f getCenter(){ return sf::Vector2f(_position.x+_shape.getSize().x/2,_position.y+_shape.getSize().y/2);}

    const sf::RectangleShape& getShape() const { return _shape; }
    sf::RectangleShape& getShape() { return _shape; }

    const sf::RectangleShape& getHitbox() const { return _hitbox; }
    sf::RectangleShape& getHitbox() { return _hitbox; }

    const std::string& getType() const { return _type; }
    const int& getID() const { return _ID; }

};

#endif
