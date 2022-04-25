#ifndef MAP_H
#define MAP_H
#include "entity.hpp"
#include <list>
#include <iterator>

class Map{
  private :
    std::list<Entity*>* entityMap;

    public :
      Map(){entityMap=new std::list<Entity*>();}
      ~Map(){delete entityMap;}

      void display(Renderer& r) const;

      void addEntity(Entity* entity);
      void deleteEntity(Entity* entity);

      // ACCESSEURS
      const std::list<Entity*>& getEntityMap() const { return *entityMap; }
      std::list<Entity*>& getEntityMap() { return *entityMap; }




};

#endif
