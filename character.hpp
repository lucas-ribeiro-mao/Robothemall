#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.hpp"


class Character : virtual public Entity{
  protected:
    int _health;
    float _speed;
  public:
    bool isDead() const {return _health<=0;}
    virtual void display(Renderer& r) const =0;

    // ACCESSEURS
    const int& getHealth() const { return _health; }
    int& getHealth() { return _health; }
};

#endif
