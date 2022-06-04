#ifndef BULLET_H
#define BULLET_H
#include "entity.hpp"
#include <vector>
#include <list>
#include "map.hpp"
#include "renderer_interface.hpp"
#include "renderer.hpp"
#include <math.h>
#include "foes.hpp"

#define BULLET_SIZE 5
#define BULLET_DAMAGE 10

using namespace std;
class Foes;
class Player;

class Bullet : virtual public Entity{
  protected:
    // speed of bullets
    float _speed;
    // damage done to foes
    float _damage;
    // direction taken by the bullet
    sf::Vector2f _direction;

  public:
    Bullet(sf::Vector2f position, float speed, sf::Vector2f direction);
    ~Bullet() {};


    // CF entity
    void display(Renderer& r) const{r.displayEntity(*this);}
    void updatePosition(){
      _shape.setPosition(_position);
      _hitbox.setPosition(_position);
    }

    void move(sf::Event& event, sf::Time& dt, Map& map);

    // ACCESSEURS
    const float& getDamage() const {return _damage;}


};

#endif
