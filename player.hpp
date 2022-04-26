#ifndef PLAYER_H
#define PLAYER_H

#include "character.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <iostream>

class Player : virtual public Character{
  private :
    int _playerID;
    bool up,right,down,left;

  public :
    Player(int playerID,int health,sf::Vector2f position, float speed);
    void display(Renderer& r) const { r.displayEntity(*this);}

    void move(sf::Event event, sf::Time dt);

    // ACCESSEURS
    const int& getId() const { return _playerID;}
    int& getId(){ return _playerID;}

};

#endif
