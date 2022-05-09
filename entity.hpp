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

    bool collision(const Entity& other){
      sf::FloatRect thisBox = this->getShape().getGlobalBounds();
      sf::FloatRect otherBox = other.getShape().getGlobalBounds();

      if(thisBox.intersects(otherBox))
        return true;
      return false;
    }

    virtual void move(sf::Event& event, sf::Time& dt, Map& map) =0;

    static int nextID() { serialID++; return serialID; }

    // ACCESSEURS
    const float& getX() const { return _position.x; }
    float& getX() { return _position.x; }
    const float& getY() const { return _position.y; }
    float& getY() { return _position.y; }

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
