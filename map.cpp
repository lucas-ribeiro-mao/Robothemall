#include "map.hpp"
#include <iostream>
#include "entity.hpp"
#include "player.hpp"
#include "foes.hpp"
#include "bullet.hpp"


Map::Map()
{
  playerMap=new std::list<Player*>();
  foesMap=new std::list<Foes*>();
  bulletMap=new std::list<Bullet*>();
}

Map::~Map()
{
  auto it_p=playerMap->begin();
  while (it_p!=playerMap->end()){
    delete (*it_p);
    ++it_p;
  }

  auto it_f=foesMap->begin();
  while (it_f!=foesMap->end()){
    delete (*it_f);
    ++it_f;
  }

  auto it_b=bulletMap->begin();
  while (it_b!=bulletMap->end()){
    delete (*it_b);
    ++it_b;
  }

  delete playerMap;
  delete foesMap;
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
  delete entity;
}

void Map::deleteEntity(Player* entity){
  //entityMap->remove(entity);
  playerMap->remove(entity);
  delete entity;
}

void Map::deleteEntity(Foes* entity){
  //entityMap->remove(entity);
  foesMap->remove(entity);
  delete entity;
}

void Map::deleteEntity(Bullet* entity){
  //entityMap->remove(entity);delete entity;
  delete entity;
  bulletMap->remove(entity);

}


void Map::addBullet(sf::Vector2f position){
  sf::Vector2f direction;
  //Search for the clothest foe to shoot at him
  if (foesMap->size()>0){
    auto it = foesMap->begin();
    direction = (*it)->getCenter();
    for (++it; it != foesMap->end();++it){
      sf::Vector2f foesPos = (*it)->getCenter();
      // calcul of distance
      if (sqrt(pow(direction.x-position.x,2)+pow(direction.y-position.y,2))>sqrt(pow(foesPos.x-position.x,2)+pow(foesPos.y-position.y,2)))
        direction = foesPos;
    }
    //std::cout<<direction.x<<" "<<direction.y<<"\n";
  }
  // if no ennemy shoot at the right
  else direction = sf::Vector2f(1,0);

  //add the bullet to the map
  Bullet *bullet = new Bullet(position, 500.0f, direction-position);
  addEntity(bullet);

}



void Map::display(Renderer& r) const{
  if(playerMap->size()>0){
    auto it_p=playerMap->begin();
    do{
      (*it_p)->display(r);
      ++it_p;

    }while (it_p!=playerMap->end());
  }

  if(foesMap->size()>0){
    auto it_f=foesMap->begin();
    do{
      (*it_f)->display(r);
      ++it_f;

    }while (it_f!=foesMap->end());
  }
  if(bulletMap->size()>0){
    for (auto it_b=bulletMap->begin(); it_b != bulletMap->end();++it_b){
      (*it_b)->display(r);

    }
  }

}


void Map::checkBulletCollision(){
  int collide = 0;
  std::list<Bullet*> bullet2Remove;
  for (auto bullet : this->getBulletMap()){
    sf::Vector2f center = (*bullet).getCenter();
    if( center.x > WIDTH_WINDOW || center.x < 0 || center.y > HEIGHT_WINDOW || center.y < 0){
      bullet2Remove.push_back(bullet);
    }
    else {
      for (auto foes : this->getFoesMap()){
        collide=(*bullet).collision(*foes);
        if(collide!=0){
          (*foes).getHit((*bullet).getDamage());
          bullet2Remove.push_back(bullet);
        }
      }
    }
  }

  for (auto bullet : bullet2Remove){
    this->deleteEntity(bullet);
  }

}

void Map::checkDeath(){
  checkBulletCollision();


  std::list<Foes*> foes2Remove;
  for (auto foes : this->getFoesMap()){
    if(foes->isDead()){
      foes2Remove.push_back(foes);
    }
  }

  std::list<Player*> player2Remove;
  for (auto player : this->getPlayerMap()){
    if(player->isDead()){
      player2Remove.push_back(player);
    }
  }

  for (auto foes : foes2Remove){
    this->deleteEntity(foes);
  }
  for (auto player : player2Remove){
    this->deleteEntity(player);
  }

}
