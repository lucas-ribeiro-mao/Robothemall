#ifndef FOES_H
#define FOES_H

#include "character.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class Foes : virtual public Character{
  protected:
    float swiftnessX,swiftnessY;

  public :
    Foes(int health, sf::Vector2f position, float speed);

    void display(Renderer& r) const {r.displayEntity(*this);}

    void move(sf::Event& event, sf::Time& dt, Map& map);

    // ACCESSEURS



};


#endif
