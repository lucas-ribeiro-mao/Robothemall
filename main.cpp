#include "renderer.hpp"
#include "player.hpp"
#include "map.hpp"
//#include "entity.hpp"
#include <iostream>
# include "foes.hpp"


int main(){

  //get the event of the window
  sf::Event event;
  sf::Vector2f v1(400.0f,400.0f);
  sf::Vector2f v2(100.0f,0.0f);
  sf::Vector2f v3(100.0f,100.0f);
  Map* map = new Map();
  Player* j1= new Player(200,v1,100.0f);
  Foes* f1= new Foes(100,v2,0.5f);
  Foes* f2= new Foes(100,v3,0.5f);
  Renderer* renderer = new Renderer(800,600);
  renderer->getWindow().setVerticalSyncEnabled(false);
  // renderer->getWindow().setFramerateLimit(30);

  std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;

  map->addEntity(j1);
  map->addEntity(f1);
  map->addEntity(f2);
  sf::Clock deltaTime;
  sf::Time dt;


  while(renderer->getIsOpen()){
    dt = deltaTime.restart();
    renderer->getWindow().pollEvent(event);
    j1->move(event, dt);
    f1->move(*j1,dt);
    f2->move(*j1,dt);
    renderer->waitForExit(event);
    renderer->render(*map);

  }




  delete renderer;
  delete j1;
  delete f1;
  delete map;
}
