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
    Map* _map = nullptr;

    Renderer* _renderer = nullptr;
    //texture of the Characters
    sf::Texture* _textureCharacters = nullptr;

    sf::Font _font;
    sf::Text _gameOverTxt;
    sf::Text _escTxt;
    sf::Text _roundTxt;
    unsigned int _cptRounds = 0;

  public :
    Game();
    ~Game();
    void initializeTexts();

    // course of the game
    void update();
    // generate an ennemy randomly on the map
    void ennemyGeneration();
    //display the game over screen
    void gameOver();
    //heal each players at the end of a round
    void healPlayers(int hp);
    // add round number on screen
    void rounds();
    // all displays, map + texts
    void display();
};

#endif
