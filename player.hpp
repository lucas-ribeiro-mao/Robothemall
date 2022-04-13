#ifndef PLAYER_H
#define PLAYER_H
#include "character.hpp"
#include "renderer.hpp"

class Player : public Character{
  private :
    int _playerID;

  public :
    Player(int playerID,int health,sf::Vector2f position);
    void display(Renderer& r) const {r.displayEntity(*this);}

};

#endif
