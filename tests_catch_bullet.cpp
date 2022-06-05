#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#endif

#include "bullet.hpp"

TEST_CASE("Bullets can be created and used")
{
  Bullet b1(sf::Vector2f(10.f,10.f), 50.f, sf::Vector2f(-1.f, 2.f));
  Bullet b2(sf::Vector2f(13.f,13.f), 50.f, sf::Vector2f(-1.f, 2.f));
  Bullet b3(sf::Vector2f(20.f,20.f), 50.f, sf::Vector2f(10.f, 10.f));

  SECTION("Getters")
  {
    sf::RectangleShape r(sf::Vector2f(BULLET_SIZE,BULLET_SIZE+2.f));
    sf::FloatRect f1 = r.getGlobalBounds();
    sf::FloatRect f2 = b1.getShape().getGlobalBounds();
    REQUIRE( f1.width == f2.width );
    REQUIRE_FALSE( f1.height == f2.height);

    REQUIRE(b1.getID() == 1);
    REQUIRE(b2.getID() == 2);

    REQUIRE( b1.getType().compare("Bullet") == 0 );

    sf::Vector2f v(10.f,10.f);
    REQUIRE(b1.getX() == v.x);
    REQUIRE(b1.getY() == v.y);
    REQUIRE(b1.getPos() == v);
    REQUIRE(b2.getPos() != v);

    sf::Vector2f center(12.5f,12.5f);
    REQUIRE( b1.getCenter() == center );
  }


  SECTION("Damage"){
    REQUIRE( b1.getDamage() == 10 );
  }


  SECTION("Collision")
  {
    REQUIRE( b1.collision(b2) == 22 );
    REQUIRE( b2.collision(b1) == 11 );
    REQUIRE( b1.collision(b3) == 0 );
  }





}
