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

  public :
    virtual void display(Renderer& r) const =0 ;

    // ACCESSEURS
    const float& getX() const { return _position.x; }
    float& getX() { return _position.x; }
    const float& getY() const { return _position.y; }
    float& getY() { return _position.y; }

    const sf::RectangleShape& getShape() const { return _shape; }
    sf::RectangleShape& getShape() { return _shape; }

    //OPERATEURS
    bool operator==(const Entity& e) const{ return _position.x==e.getX() && _position.y==e.getY() && _shape.getSize()==e.getShape().getSize();};
};

#endif
