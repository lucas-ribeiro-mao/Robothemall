#include "game.hpp"

Game::Game(){
  _map = new Map();
  _textureCharacters = new sf::Texture();
  _textureCharacters->loadFromFile("Sprites/robots.png");

  //Starting position of the two player
  sf::Vector2f v1(400.0f,400.0f);
  sf::Vector2f v2(500.0f,50.0f);

  Player* j1= new Player(200,v1,100.0f,1,_textureCharacters);
  Player* j2= new Player(200,v2,100.0f,2,_textureCharacters);


  _renderer = new Renderer(WIDTH_WINDOW,HEIGHT_WINDOW);
  _renderer->getWindow().setVerticalSyncEnabled(false);
  _renderer->getWindow().setFramerateLimit(60);
  srand (static_cast <unsigned> (time(0)));
  std::cout << "Close the window or press Esc. to close the game." <<  std::endl;

  //add the players to the map
  _map->addEntity(j1);
  _map->addEntity(j2);
}

Game::~Game(){
  delete _renderer;
  delete _map;
  delete _textureCharacters;
}


void Game::update(){
  sf::Clock deltaTime;
  sf::Time dt;
  size_t nbFoePerRound=2;
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
    _renderer->render(*_map);

    //recreate a set of ennemies (one more each time)
    if (_map->getFoesMap().size()==0){
      for (size_t i = 0; i < nbFoePerRound; i++) {
        ennemyGeneration();
      }
      nbFoePerRound++;

      for (auto it=_map->getPlayerMap().begin(); it!=_map->getPlayerMap().end(); ++it){
        //Heal all the surviving player
          (*it)->heal(20);

      }
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
  sf::Font font;
  sf::Text text;
  sf::Text textEsc;


  // select the font
  font.loadFromFile("Fonts/SuperLegendBoy.ttf");
  text.setFont(font);
  textEsc.setFont(font);

  // set the string to display
  text.setString("Game over");
  textEsc.setString("Press Esc to quit.");

  // set the character size
  text.setCharacterSize(100);
  textEsc.setCharacterSize(40);

  // set the color
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold);
  text.setPosition(WIDTH_WINDOW/2-text.getGlobalBounds().width/2,HEIGHT_WINDOW/2-text.getGlobalBounds().height/2);

  textEsc.setStyle(sf::Text::Bold);
  textEsc.setFillColor(sf::Color(180,180,180,255));
  textEsc.setPosition(WIDTH_WINDOW/2-textEsc.getGlobalBounds().width/2,HEIGHT_WINDOW/2-textEsc.getGlobalBounds().height/2+text.getGlobalBounds().height+20);

  _renderer->getWindow().clear();
  _renderer->getWindow().draw(text);
  _renderer->getWindow().draw(textEsc);
  _renderer->getWindow().display();

  while(_renderer->getIsOpen())
  {
    _renderer->getWindow().pollEvent(_event);
    _renderer->waitForExit(_event);
  }
}
