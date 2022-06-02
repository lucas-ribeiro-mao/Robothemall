#ifndef GAME_H
#define GAME_H

#include "renderer.hpp"
#include "player.hpp"
#include "map.hpp"
#include <iostream>
#include "foes.hpp"
#include "bullet.hpp"
#include <unistd.h>

#define SPAWN_PROTECTION 100

class Game {
  protected :
    // used for the key pressed
    sf::Event _event;
    // Map of the game
    Map* _map;

    Renderer* _renderer;
    //texture of the Characters
    sf::Texture* _textureCharacters;

  public :
    Game();
    ~Game();

    // course of the game
    void update();
    // generate an ennemy randomly on the map
    void ennemyGeneration();
    //display the game over screen
    void gameOver();
};

#endif
