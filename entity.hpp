#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Renderer;

class Entity {
  protected :
    sf::Vector2f _position;
    sf::RectangleShape _hitbox;
    sf::RectangleShape _shape;

    int _ID;
    static int serialID;

  public :
    Entity(){_ID = nextID();}

    virtual void display(Renderer& r) const =0;

    static int nextID() { serialID++; return serialID; }

    // ACCESSEURS
    const float& getX() const { return _position.x; }
    float& getX() { return _position.x; }
    const float& getY() const { return _position.y; }
    float& getY() { return _position.y; }

    sf::Vector2f getCenter(){ return sf::Vector2f(_position.x+_shape.getSize().x/2,_position.y+_shape.getSize().y/2);}

    const sf::RectangleShape& getShape() const { return _shape; }
    sf::RectangleShape& getShape() { return _shape; }

    //OPERATEURS
    bool operator==(const Entity& e) const{ return _position.x==e.getX() && _position.y==e.getY() && _shape.getSize()==e.getShape().getSize();};
};

#endif
