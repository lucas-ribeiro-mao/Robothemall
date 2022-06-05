#ifndef PLAYER_H
#define PLAYER_H

#include "character.hpp"
#include "renderer.hpp"
#include "renderer_interface.hpp"
#include <cmath>
#include <iostream>
#include "foes.hpp"
#include <vector>
#include <sys/time.h>
#include <ctime>

#define SHOOTRATE 200

using namespace std;

class Player : virtual public Character{
  protected :
    bool up,right,down,left, _shoot, _shootDelay;
    struct timeval previousShot, currentShot;
    struct timeval prevInvState, currInvState;


    sf::Clock timeCounter;
    std::vector<sf::Keyboard::Key> command4Direction;
    bool _isInvicible;
    unsigned int _shootRate = 200;
    unsigned int _invicibleDuration = 300; // in milliseconds
    sf::Vector2u _placeTexture;


  public :
    Player(int health,sf::Vector2f position, float speed, int id, sf::Texture* texture);
    //~Player(){};
    void display(Renderer& r) const { r.displayEntity(*this);}
    void move(sf::Event& event, sf::Time& dt, Map& map);

    // create a Bullet to kill enemies
    void shoot(Map& map);

    //if the time between the previous shot is big enougth, _shootDelay=True
    void shootDelay();
    //remove health to the palyer
    void getHit(const int& dmg);
    //after getting hit the player is invincible for a few seconds : _isInvicible True
    void invincibleDelay();
    // ACCESSEURS


};

#endif
