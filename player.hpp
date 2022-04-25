#ifndef PLAYER_H
#define PLAYER_H
#include "entity.hpp"
#include "character.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <iostream>

class Player : virtual public Character{
  private :
    int _playerID;

  public :
    Player(int playerID,int health,sf::Vector2f position);
    void display(Renderer& r) const { r.displayEntity(*this);}

    // ACCESSEURS
    const int& getId() const { return _playerID;}
    int& getId(){ return _playerID;}

};

#endif
