#ifndef MAP_H
#define MAP_H
include "entity.hpp"


class Map{
  private :
    std::list<Entity> entityMap = nullptr;

    public :
      Map(){entityMap= new std::list<Entity>;}
      ~Map(){delete entityMap;}

      void display(Renderer& r);

      // ACCESSEURS
      const std::list<Entity>& getEntityMap() const { return entityMap; }
      std::list<Entity>& getEntityMap() { return entityMap; }
};

#endif
