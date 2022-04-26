#include "map.hpp"
#include <iostream>
#include "entity.hpp"

int Entity::serialID=0;

void Map::addEntity(Entity* entity){
  entityMap->push_back(entity);
}


void Map::deleteEntity(Entity* entity){
  entityMap->remove(entity);
}

void Map::display(Renderer& r) const{
  auto it=entityMap->begin();
  //std::cout<<"scooby";
  //std::cout<<entityMap->size()<<"\n";
  do{
    //std::cout<<(*it)->getX()<<"\n";

    (*it)->display(r);
    ++it;

  }while (it!=entityMap->end());


  /*for (auto it=entityMap->begin(); it!=entityMap->end(); ++it){
    it->display(r);
  }*/

}
