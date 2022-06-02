#include "character.hpp"
#include "player.hpp"
#include "foes.hpp"

void Character::checkCollision(Map& map){
  // if !=0 -> colision occurs
  int collide;

  // check the Character collision with all players
  for (auto player : map.getPlayerMap()){
    if ((*this).getID()!=player->getID()){
      collide=(*this).collision(*player);

      if(collide!=0){
        // remove health if the Character is a Foe
        if ((*this).getType() == "Foes") (player)->getHit(DAMAGE);


        // right
        if(collide%10==1){
          //remove the movement
          _velocity.x = 0.f;
          // Place the entity next to the collided one
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

  //Same process with all the foes

  collide=0;
  for (auto foes : map.getFoesMap()){
    if ((*this).getID()!=foes->getID()){
      collide=(*this).collision(*foes);
      if(collide!=0){
        if ((*this).getType() == "Player") (*this).getHit(DAMAGE);

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

void Character::heal(const int& heal){
  _health += heal;
  if( _health > _maxHealth )
    _health = _maxHealth;
}
