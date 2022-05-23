#include "map.hpp"
#include <iostream>
#include "entity.hpp"
#include "player.hpp"
#include "foes.hpp"
#include "bullet.hpp"

int Entity::serialID=0;

Map::Map()
{
  entityMap=new std::list<Entity*>();
  playerMap=new std::list<Player*>();
  foesMap=new std::list<Foes*>();
  bulletMap=new std::list<Bullet*>();
}

Map::~Map()
{
  delete entityMap;
  delete playerMap;
  delete foesMap;
  // for (int i = bulletMap->size()-1; i>=0;i--)
  //   delete *bulletMap[i];
  delete bulletMap;
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

void Map::addEntity(Bullet* entity){
  //entityMap->push_back(entity);
  bulletMap->push_back(entity);
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

void Map::deleteEntity(Bullet* entity){
  //entityMap->remove(entity);
  bulletMap->remove(entity);
}


void Map::addBullet(sf::Vector2f position){
  sf::Vector2f direction;
  if (foesMap->size()>0){
    auto it = foesMap->begin();
    direction = (*it)->getCenter();
    ++it;
    for (it; it != foesMap->end();++it){
      sf::Vector2f foesPos = (*it)->getCenter();
      if (sqrt(pow(direction.x-position.x,2)+pow(direction.y-position.y,2))>sqrt(pow(foesPos.x-position.x,2)+pow(foesPos.y-position.y,2)))
        direction = foesPos;
    }
    //std::cout<<direction.x<<" "<<direction.y<<"\n";
  }
  else direction = sf::Vector2f(1,0);
  Bullet *bullet = new Bullet(position, 500.0f, direction-position);
  addEntity(bullet);

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

  auto it_b=bulletMap->begin();
  for (it_b; it_b != bulletMap->end();++it_b){
    (*it_b)->display(r);

  }


}
