#include "renderer.hpp"
#include "player.hpp"
//#include "map.hpp"
#include <iostream>

int main(){
  sf::Vector2f v1(400.0f,400.0f);
  Player* j1= new Player(1,200,v1);

  Renderer* renderer = new Renderer(800,800);

  while(1){
    j1->display(*renderer);
  }



  delete renderer;
  delete j1;

}
