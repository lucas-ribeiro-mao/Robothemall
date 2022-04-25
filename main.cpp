#include "renderer.hpp"
#include "player.hpp"
#include "map.hpp"
//#include "entity.hpp"
#include <iostream>

int main(){
  sf::Vector2f v1(400.0f,400.0f);
  Map* map = new Map();
  Player* j1= new Player(1,200,v1);

  Renderer* renderer = new Renderer(800,600);

  std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;
  std::cout<<"oh\n";
  map->addEntity(j1);
  std::cout<<map->getEntityMap().front()->getX();
  std::cout<<"oh\n";
  while(renderer->getIsOpen()){
    renderer->waitForExit();
    renderer->render(*map);
  }




  delete renderer;
  delete j1;
  delete map;
}
