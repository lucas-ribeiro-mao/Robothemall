#include "renderer.hpp"
#include "player.hpp"
#include "map.hpp"
//#include "entity.hpp"
#include <iostream>
# include "foes.hpp"
#include "bullet.hpp"




int main(){

  //get the event of the window
  sf::Event event;
  sf::Vector2f v1(400.0f,400.0f);
  sf::Vector2f v2(100.0f,100.0f);
  sf::Vector2f v3(100.0f,0.0f);
  sf::Vector2f v4(500.0f,50.0f);
  Map* map = new Map();
  Player* j1= new Player(200,v1,100.0f,1);
  Player* j2= new Player(200,v4,100.0f,2);
  Foes* f1= new Foes(100,v2,75.0f);
  Foes* f2= new Foes(100,v3,50.0f);
  // Foes* f3= new Foes(100,v3,50.0f);
  // Foes* f4= new Foes(100,v3,50.0f);
  // Foes* f5= new Foes(100,v3,50.0f);
  Renderer* renderer = new Renderer(WIDTH_WINDOW,HEIGHT_WINDOW);
  renderer->getWindow().setVerticalSyncEnabled(false);
  // renderer->getWindow().setFramerateLimit(30);

  std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;

  map->addEntity(j1);
  map->addEntity(j2);
  map->addEntity(f1);
  map->addEntity(f2);
  // map->addEntity(f3);
  // map->addEntity(f4);
  // map->addEntity(f5);

  sf::Clock deltaTime;
  sf::Time dt;


  while(renderer->getIsOpen()){
    dt = deltaTime.restart();
    renderer->getWindow().pollEvent(event);
    for (auto it=map->getPlayerMap().begin(); it!=map->getPlayerMap().end(); ++it){
      //for (auto it=map->getEntityMap().begin(); it!=map->getEntityMap().end(); ++it){
        (*it)->move(event, dt, *map);
      //}
    }
    for (auto it=map->getFoesMap().begin(); it!=map->getFoesMap().end(); ++it){
      //for (auto it=map->getEntityMap().begin(); it!=map->getEntityMap().end(); ++it){
        (*it)->move(event, dt, *map);
      //}
    }
    for (auto it=map->getBulletMap().begin(); it!=map->getBulletMap().end(); ++it){
      //for (auto it=map->getEntityMap().begin(); it!=map->getEntityMap().end(); ++it){
        (*it)->move(event, dt, *map);
      //}
    }
    map->checkDeath();
    //std::cout<<j1->getX()<<"  "<<j1->getY()<<"\n";
    //std::cout<<f1->getX()<<"  "<<f1->getY()<<"\n\n\n";
    renderer->waitForExit(event);
    renderer->render(*map);

  }




  delete renderer;
  delete map;
  // delete j1;
  // delete j2;
  // delete f1;
  // delete f2;
  // delete f3;
  // delete f4;
  // delete f5;

}
