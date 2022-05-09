#ifndef MAP_H
#define MAP_H
#include "entity.hpp"
#include <list>
#include <memory>
#include <iterator>

using namespace std;

class Renderer;
class Player;
class Foes;


class Map{
  private :
    std::list<Entity*>* entityMap;
    std::list<Player*>* playerMap;
    std::list<Foes*>* foesMap;
    // std::list<Item*>* itemMap;
    // std::list<Bullet*> bulletMap;

    public :
      Map();
      ~Map();

      void display(Renderer& r) const;

      void addEntity(Entity* entity);
      void addEntity(Player* entity);
      void addEntity(Foes* entity);
      void deleteEntity(Entity* entity);
      void deleteEntity(Player* entity);
      void deleteEntity(Foes* entity);



      // ACCESSEURS
      const std::list<Entity*>& getEntityMap() const { return *entityMap; }
      std::list<Entity*>& getEntityMap() { return *entityMap; }

      const std::list<Player*>& getPlayerMap() const { return *playerMap; }
      std::list<Player*>& getPlayerMap() { return *playerMap; }

      const std::list<Foes*>& getFoesMap() const { return *foesMap; }
      std::list<Foes*>& getFoesMap() { return *foesMap; }




};

#endif
