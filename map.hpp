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
class Bullet;


class Map{
  private :

    // lists of all entities
    std::list<Entity*>* entityMap = nullptr;
    std::list<Player*>* playerMap = nullptr;
    std::list<Foes*>* foesMap = nullptr;
    // std::list<Item*>* itemMap;
    std::list<Bullet*>* bulletMap = nullptr;

    public :
      Map();
      ~Map();

      //display all the entity in the map
      void display(Renderer& r) const;

      // add entities to their respective lists
      void addEntity(Entity* entity);
      void addEntity(Player* entity);
      void addEntity(Foes* entity);
      void addEntity(Bullet* entity);

      // delete entities to their respective lists
      void deleteEntity(Entity* entity);
      void deleteEntity(Player* entity);
      void deleteEntity(Foes* entity);
      void deleteEntity(Bullet* entity);

      //When players shoot add a bulet toward the clothest ennemy
      void addBullet(sf::Vector2f position);

      //check if a bullet collide with a foe
      void checkBulletCollision();

      // check if a character died
      void checkDeath();

      // ACCESSEURS
      const std::list<Entity*>& getEntityMap() const { return *entityMap; }
      std::list<Entity*>& getEntityMap() { return *entityMap; }

      const std::list<Player*>& getPlayerMap() const { return *playerMap; }
      std::list<Player*>& getPlayerMap() { return *playerMap; }

      const std::list<Foes*>& getFoesMap() const { return *foesMap; }
      std::list<Foes*>& getFoesMap() { return *foesMap; }

      const std::list<Bullet*>& getBulletMap() const { return *bulletMap; }
      std::list<Bullet*>& getBulletMap() { return *bulletMap; }


};

#endif
