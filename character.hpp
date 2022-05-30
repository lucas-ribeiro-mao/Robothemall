#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.hpp"
#include <vector>
#include <list>
#include "map.hpp"

using namespace std;
class Foes;
class Player;

class Character : virtual public Entity{
  protected:
    int _health;
    int _maxHealth;
    std::vector<sf::RectangleShape> healthBar;
    float _speed;


  public:
    Character() : Entity() {};
    bool isDead() const {return _health<=0;}

    virtual void display(Renderer& r) const =0;


    void cancelMove() {
      healthBar[0].setPosition(_position);
      healthBar[1].setPosition(_position);
      _hitbox.setPosition(_position);
      _shape.setPosition(_position);
    };

    void setHealthBar(){
      healthBar.push_back(sf::RectangleShape(sf::Vector2f(100.0f,10.0f)));
      healthBar[0].setPosition(this->getCenter().x-50.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[0].setFillColor(sf::Color::Red);
      healthBar[0].setOutlineThickness(2.0f);
      healthBar[0].setOutlineColor(sf::Color::White);

      healthBar.push_back(sf::RectangleShape(sf::Vector2f(100.0f,10.0f)));
      healthBar[1].setPosition(this->getCenter().x-50.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1].setFillColor(sf::Color::Green);
    }

    void updatePosition(){
      healthBar[0].setPosition(this->getCenter().x-50.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1].setPosition(this->getCenter().x-50.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1].setScale(((float)_health/(float)_maxHealth),1);
      _shape.setPosition(_position);
      _hitbox.setPosition(_position);
    }

    virtual void move(sf::Event& event, sf::Time& dt, Map& map) =0;
    // ACCESSEURS
    const int& getHealth() const { return _health; }
    int& getHealth() { return _health; }

    const std::vector<sf::RectangleShape>& getHealthBar() const { return healthBar; }
    std::vector<sf::RectangleShape>& getHealthBar() { return healthBar; }

    void checkCollision(Map& map);
    void getHit(Foes& foes, Map& map) {};

};

#endif
