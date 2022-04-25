#include "map.hpp"
#include <iostream>
#include "entity.hpp"
void Map::addEntity(Entity& entity){
  entityMap->push_back(entity);
}


void Map::deleteEntity(Entity& entity){
  entityMap->remove(entity);
}

void Map::display(Renderer& r) const{
  auto it=entityMap->begin();
  //std::cout<<"scooby";
  do{
    //std::cout<<"do";
    //std::cout<<it->getX();
    it->display(r);
    if(it!=entityMap->end())
      ++it;
  }while (it!=entityMap->end());


  /*for (auto it=entityMap->begin(); it!=entityMap->end(); ++it){
    it->display(r);
  }*/

}
