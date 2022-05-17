#include "character.hpp"
#include "player.hpp"
#include "foes.hpp"

void Character::checkCollision(Map& map){
  int collide;
  for (auto player : map.getPlayerMap()){
    if ((*this).getID()!=player->getID()){
      collide=(*this).collision(*player);
      //std::cout<<collide<<"\n";
      if(collide!=0){
        // right
        if(collide%10==1){
          _velocity.x = 0.f;
          _position.x=player->getPos().x + player->getHitbox().getSize().x;
          break;
        }
        // left
        else if(collide%10==2){
          _velocity.x = 0.f;
          _position.x=player->getPos().x - _hitbox.getSize().x;
          break;
        }
        // down
        if(collide/10%10==1){
          _velocity.y = 0.f;
          _position.y=player->getPos().y + player->getHitbox().getSize().y;
          break;
        }
        // up
        else if(collide/10%10==2){
          _velocity.y = 0.f;
          _position.y=player->getPos().y - _hitbox.getSize().y;
          break;
        }
      }
    }
  }

  collide=0;
  for (auto foes : map.getFoesMap()){
    if ((*this).getID()!=foes->getID()){
      collide=(*this).collision(*foes);
      if(collide!=0){
        if(collide%10==1){

          _position.x=foes->getPos().x + foes->getHitbox().getSize().x;
          break;
        }
        else if(collide%10==2){

          _position.x=foes->getPos().x - _hitbox.getSize().x;
          break;
        }
        if(collide/10%10==1){

          _position.y=foes->getPos().y + foes->getHitbox().getSize().y;
          break;
        }
        else if(collide/10%10==2){

          _position.y=foes->getPos().y - _hitbox.getSize().y;
          break;
        }
      }
    }
  }
}
