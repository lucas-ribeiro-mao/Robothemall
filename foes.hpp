#ifndef FOES_H
#define FOES_H

#include "character.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <iostream>
#include <cmath>

#define MIN_SPEED 75.0f
#define MAX_SPEED 80.0f

using namespace std;

class Foes : virtual public Character{
  protected:
    float swiftnessX,swiftnessY;

  public :
    Foes(int health, sf::Vector2f position, float speed, sf::Texture* texture);

    void display(Renderer& r) const {r.displayEntity(*this);}

    void move(sf::Event& event, sf::Time& dt, Map& map);
    //void getHit(Bullet& bullet, Map& map);
    void getHit(const float& dmg){ _health -= dmg;}

    // ACCESSEURS



};


#endif
