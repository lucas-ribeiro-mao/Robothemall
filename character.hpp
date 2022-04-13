#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.hpp"


class Character : public Entity{
  protected:
    int _health;

  public:
    bool isDead() const {return _health<=0;}


    // ACCESSEURS
    const int& getHealth() const { return _health; }
    int& getHealth() { return _health; }
};

#endif
