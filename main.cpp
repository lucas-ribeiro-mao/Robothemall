#include "renderer.hpp"
#include "player.hpp"
#include "map.hpp"
//#include "entity.hpp"
#include <iostream>


int main(){

  //get the event of the window
  sf::Event event;
  sf::Vector2f v1(400.0f,400.0f);
  Map* map = new Map();
  Player* j1= new Player(1,200,v1,100.0f);

  Renderer* renderer = new Renderer(800,600);
  renderer->getWindow().setVerticalSyncEnabled(false);
  // renderer->getWindow().setFramerateLimit(30);

  std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;

  map->addEntity(j1);

  sf::Clock deltaTime;
  sf::Time dt;
  while(renderer->getIsOpen()){
    dt = deltaTime.restart();
    renderer->getWindow().pollEvent(event);
    j1->move(event, dt);
    renderer->waitForExit(event);
    renderer->render(*map);

  }




  delete renderer;
  delete j1;
  delete map;
}
