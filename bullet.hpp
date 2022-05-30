#ifndef BULLET_H
#define BULEET_H
#include "entity.hpp"
#include <vector>
#include <list>
#include "map.hpp"
#include "renderer_interface.hpp"
#include "renderer.hpp"
#include <math.h>
#include "foes.hpp"

using namespace std;
class Foes;
class Player;

class Bullet : virtual public Entity{
  protected:
    float _speed;
    sf::Vector2f _direction;

  public:
    Bullet(sf::Vector2f position, float speed, sf::Vector2f direction);
    ~Bullet() {};

    void display(Renderer& r) const{r.displayEntity(*this);}


    void cancelMove() {
      _hitbox.setPosition(_position);
      _shape.setPosition(_position);
    };


    void updatePosition(){
      _shape.setPosition(_position);
      _hitbox.setPosition(_position);
    }

    void move(sf::Event& event, sf::Time& dt, Map& map);
    // ACCESSEURS

    void checkCollision(Map& map);

};

#endif
