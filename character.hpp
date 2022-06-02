#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.hpp"
#include <vector>
#include <list>
#include "map.hpp"

#define DAMAGE 10.0f


using namespace std;
class Foes;
class Player;

class Character : virtual public Entity{
  protected:
    int _health;
    int _maxHealth;
    std::vector<sf::RectangleShape*> healthBar;
    float _speed;


  public:
    Character() : Entity() {};
    ~Character() {
      for(size_t i=0 ; i<2;i++)
        delete(healthBar[i]);
    }

    // True if the entity does not have health anymore
    bool isDead() const {return _health<=0;}

    virtual void display(Renderer& r) const =0;



    //create an healthBar : one red rectangle covered by a green one that diminues in fonction of the health
    void setHealthBar(){
      healthBar.push_back(new sf::RectangleShape(sf::Vector2f(50.0f,4.0f)));
      healthBar[0]->setPosition(this->getCenter().x-25.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[0]->setFillColor(sf::Color::Red);
      healthBar[0]->setOutlineThickness(1.0f);
      healthBar[0]->setOutlineColor(sf::Color::White);

      healthBar.push_back(new sf::RectangleShape(sf::Vector2f(50.0f,4.0f)));
      healthBar[1]->setPosition(this->getCenter().x-25.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1]->setFillColor(sf::Color::Green);
    }

    //set the Character at the correct place after the movement has been choosen
    void updatePosition(){
      healthBar[0]->setPosition(this->getCenter().x-25.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1]->setPosition(this->getCenter().x-25.0f,this->getCenter().y-_shape.getSize().y/2-20.0f);
      healthBar[1]->setScale(((float)_health/(float)_maxHealth),1);
      _shape.setPosition(_position);
      _hitbox.setPosition(_position);
    }


    virtual void move(sf::Event& event, sf::Time& dt, Map& map) =0;

    // detect if the caracter collide with anything on the field
    void checkCollision(Map& map);

    //remove health from the character
    virtual void getHit(const float& dmg) =0;

    //give health to the Character
    void heal(const int& heal);

    // ACCESSEURS

    const int& getHealth() const { return _health; }
    int& getHealth() { return _health; }


    const std::vector<sf::RectangleShape*> getHealthBar() const { return healthBar; }
    std::vector<sf::RectangleShape*> getHealthBar() { return healthBar; }



};

#endif
