
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <unistd.h>

#include "player.hpp"

TEST_CASE("Players can be created and used")
{
  sf::Texture textures;
  textures.loadFromFile("Sprites/robots.png");

  Player p1(100, sf::Vector2f(10.f,10.f), 100.f, 1, &textures);
  Player p2(100, sf::Vector2f(13.f,13.f), 100.f, 1, &textures);
  Player p3(100, sf::Vector2f(200.f,200.f), 100.f, 1, &textures);

  SECTION("Getters")
  {
    sf::RectangleShape r(sf::Vector2f(32.f,34.f));
    sf::FloatRect f1 = r.getGlobalBounds();
    sf::FloatRect f2 = p1.getShape().getGlobalBounds();
    REQUIRE( f1.width == f2.width );
    REQUIRE_FALSE( f1.height == f2.height);

    REQUIRE( p1.getType().compare("Player") == 0 );

  }

  SECTION("Collision")
  {
    REQUIRE( p1.collision(p2) == 22 );
    REQUIRE( p2.collision(p1) == 11 );
    REQUIRE( p1.collision(p3) == 0 );
  }

  SECTION("Health, damage, invicibility")
  {
    REQUIRE(p1.getHealth() == 100);
    p1.getHit(10);
    p1.invincibleDelay();
    REQUIRE(p1.getHealth() == 90);
    REQUIRE(p1.isDead() == 0);

    // p1 is now invincible
    p1.getHit(20);
    REQUIRE_FALSE(p1.getHealth() == 70);
    usleep(350000);
    p1.invincibleDelay();
    p1.getHit(20);
    REQUIRE(p1.getHealth() == 70);

    p1.heal(10);
    REQUIRE(p1.getHealth() == 80);


    p2.getHit(100);
    REQUIRE(p2.getHealth() == 0);
    REQUIRE(p2.isDead() == 1);

  }


}
