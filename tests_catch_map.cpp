#include "catch.hpp"

#include "map.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "foes.hpp"

TEST_CASE("Map can be created and used")
{
  Map* map = new Map();

  sf::Texture textures;
  textures.loadFromFile("Sprites/robots.png");

  Player* p1 = new Player(100, sf::Vector2f(10.f,10.f), 100.f, 1, &textures);
  Foes* f1 = new Foes(100, sf::Vector2f(10.f,10.f), 100.f, &textures);
  map->addEntity(p1);
  map->addEntity(f1);
  p1->shoot(*map);
  p1->shoot(*map);

  REQUIRE(map->getBulletMap().size() == 2);
  REQUIRE(map->getPlayerMap().size() == 1);
  REQUIRE(map->getFoesMap().size() == 1);

  delete map;


}
