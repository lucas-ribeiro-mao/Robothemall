#ifndef FOES_H
#define FOES_H

#include "character.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <iostream>
#include <cmath>

class Foes : virtual public Character{

  public :
    Foes(int health, sf::Vector2f position, float speed);

    void display(Renderer& r) const {r.displayEntity(*this);}

    void move(Player j1, sf::Time dt);

    // ACCESSEURS



};


#endif
