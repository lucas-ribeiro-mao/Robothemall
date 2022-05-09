#ifndef PLAYER_H
#define PLAYER_H

#include "character.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <cmath>
#include <iostream>
#include "foes.hpp"

using namespace std;

class Player : virtual public Character{
  private :
    bool up,right,down,left;

  public :
    Player(int health,sf::Vector2f position, float speed);
    void display(Renderer& r) const { r.displayEntity(*this);}


    void move(sf::Event& event, sf::Time& dt, Map& map);

    // ACCESSEURS


};

#endif
