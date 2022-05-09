#include "map.hpp"
#include <iostream>
#include "entity.hpp"
#include "player.hpp"
#include "foes.hpp"

int Entity::serialID=0;

Map::Map()
{
  entityMap=new std::list<Entity*>();
  playerMap=new std::list<Player*>();
  foesMap=new std::list<Foes*>();
}

Map::~Map()
{
  delete entityMap;
  delete playerMap;
  delete foesMap;
}

void Map::addEntity(Entity* entity){
  entityMap->push_back(entity);
}

void Map::addEntity(Player* entity){
  //entityMap->push_back(entity);
  playerMap->push_back(entity);
}

void Map::addEntity(Foes* entity){
  //entityMap->push_back(entity);
  foesMap->push_back(entity);
}


void Map::deleteEntity(Entity* entity){
  entityMap->remove(entity);
}

void Map::deleteEntity(Player* entity){
  //entityMap->remove(entity);
  playerMap->remove(entity);
}

void Map::deleteEntity(Foes* entity){
  //entityMap->remove(entity);
  foesMap->remove(entity);
}

void Map::display(Renderer& r) const{
  auto it_p=playerMap->begin();
  do{
    (*it_p)->display(r);
    ++it_p;

  }while (it_p!=playerMap->end());

  auto it_f=foesMap->begin();
  do{
    (*it_f)->display(r);
    ++it_f;

  }while (it_f!=foesMap->end());


}
