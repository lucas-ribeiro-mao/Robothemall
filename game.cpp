#include "game.hpp"

Game::Game(){
  _renderer = new Renderer(WIDTH_WINDOW,HEIGHT_WINDOW);
  _renderer->getWindow().setVerticalSyncEnabled(false);
  _renderer->getWindow().setFramerateLimit(60);
  srand (static_cast <unsigned> (time(0)));
  std::cout << "Close the window or press Esc. to close the game." <<  std::endl;

  _textureCharacters = new sf::Texture();
  _textureCharacters->loadFromFile("Sprites/robots.png");

  _map = new Map();

  //Starting position of the two player
  sf::Vector2f v1(400.0f,400.0f);
  sf::Vector2f v2(500.0f,50.0f);

  Player* j1= new Player(200,v1,100.0f,1,_textureCharacters);
  Player* j2= new Player(200,v2,100.0f,2,_textureCharacters);

  //add the players to the map
  _map->addEntity(j1);
  _map->addEntity(j2);

  initializeTexts();

}

Game::~Game(){
  delete _map;
  delete _textureCharacters;
  delete _renderer;
}

void Game::initializeTexts(){
  // select the font
  _font.loadFromFile("Fonts/SuperLegendBoy.ttf");
  _gameOverTxt.setFont(_font);
  _escTxt.setFont(_font);
  _roundTxt.setFont(_font);

  // set the string to display
  _gameOverTxt.setString("Game over");
  _escTxt.setString("Press Esc to quit.");

  // set the character size
  _gameOverTxt.setCharacterSize(100);
  _escTxt.setCharacterSize(40);
  _roundTxt.setCharacterSize(24);

  // set the color
  _gameOverTxt.setFillColor(sf::Color::Red);
  _gameOverTxt.setStyle(sf::Text::Bold);
  _gameOverTxt.setPosition(WIDTH_WINDOW/2-_gameOverTxt.getGlobalBounds().width/2,HEIGHT_WINDOW/2-_gameOverTxt.getGlobalBounds().height/2);

  _escTxt.setStyle(sf::Text::Bold);
  _escTxt.setFillColor(sf::Color(180,180,180,255));
  _escTxt.setPosition(WIDTH_WINDOW/2-_escTxt.getGlobalBounds().width/2,HEIGHT_WINDOW/2-_escTxt.getGlobalBounds().height/2+_gameOverTxt.getGlobalBounds().height+20);

  _roundTxt.setStyle(sf::Text::Bold);
  _roundTxt.setFillColor(sf::Color(255,255,255,175));
  _roundTxt.setPosition(10,10);
}

void Game::update(){
  sf::Clock deltaTime;
  sf::Time dt;
  while(_renderer->getIsOpen()){
    dt = deltaTime.restart();
    _renderer->getWindow().pollEvent(_event);

    // make all the entities move
    for (auto it=_map->getPlayerMap().begin(); it!=_map->getPlayerMap().end(); ++it){
        (*it)->move(_event, dt, *_map);
    }
    for (auto it=_map->getFoesMap().begin(); it!=_map->getFoesMap().end(); ++it){
        (*it)->move(_event, dt, *_map);
    }
    for (auto it=_map->getBulletMap().begin(); it!=_map->getBulletMap().end(); ++it){
        (*it)->move(_event, dt, *_map);
    }

    //check if some Characters died
    _map->checkDeath();

    //render the windows and check for exit

    _renderer->waitForExit(_event);
    this->display();

    //recreate a set of ennemies (one more each time)
    if (_map->getFoesMap().size()==0){
      for (unsigned int i = 0; i < (2 + _cptRounds); i++) {
        ennemyGeneration();
      }
      _cptRounds++;


    }

    if (_map->getPlayerMap().size()==0){
        gameOver();
    }
  }
}

void Game::ennemyGeneration(){

  const Player* j1 = _map->getPlayerMap().front();
  const Player* j2 = _map->getPlayerMap().back();

  float r1,r2;

  // select a random x coordinate at least "SPAWN_PROTECTION" distance from the players
  do{
    r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/WIDTH_WINDOW));
  }  while (abs(j1->getCenter().x-r1)<SPAWN_PROTECTION && abs(j2->getCenter().x-r1)<SPAWN_PROTECTION);

  do{
    r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/HEIGHT_WINDOW));
  } while (abs(j1->getCenter().y-r2)<SPAWN_PROTECTION && abs(j2->getCenter().y-r2)<SPAWN_PROTECTION);


  sf::Vector2f pos(r1,r2);
  float speed = MIN_SPEED + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(MAX_SPEED-MIN_SPEED)));

  Foes* f1= new Foes(100,pos,speed,_textureCharacters);
  _map->addEntity(f1);
}

void Game::gameOver(){

  _renderer->getWindow().clear();
  _renderer->getWindow().draw(_gameOverTxt);
  _renderer->getWindow().draw(_escTxt);
  _renderer->getWindow().draw(_roundTxt);
  _renderer->getWindow().display();

  while(_renderer->getIsOpen())
  {
    _renderer->getWindow().pollEvent(_event);
    _renderer->waitForExit(_event);
  }
}

void Game::healPlayers(int hp){
  for (auto it=_map->getPlayerMap().begin(); it!=_map->getPlayerMap().end(); ++it){
    //Heal all the surviving player
      (*it)->heal(hp);
  }
}

void Game::rounds(){
  std::string text = "Round " + std::to_string(_cptRounds);

  _roundTxt.setString(text);
  _renderer->getWindow().draw(_roundTxt);
}

void Game::display(){
  _renderer->clear();
  rounds();
  _renderer->render(*_map);
  _renderer->display();
}
