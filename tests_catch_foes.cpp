#include "catch.hpp"

#include "foes.hpp"

TEST_CASE("Foes can be created and used")
{
  sf::Texture textures;
  textures.loadFromFile("Sprites/robots.png");

  Foes f1(100, sf::Vector2f(10.f,10.f), 100.f, &textures);
  Foes f2(100, sf::Vector2f(13.f,13.f), 100.f, &textures);
  Foes f3(100, sf::Vector2f(200.f,200.f), 100.f, &textures);

  SECTION("Getters")
  {
    sf::RectangleShape r(sf::Vector2f(32.f,34.f));
    sf::FloatRect fr1 = r.getGlobalBounds();
    sf::FloatRect fr2 = f1.getShape().getGlobalBounds();
    REQUIRE( fr1.width == fr2.width );
    REQUIRE_FALSE( fr1.height == fr2.height);

    REQUIRE( f1.getType().compare("Foes") == 0 );
    REQUIRE_FALSE( f1.getType().compare("Player") == 0);

  }

  SECTION("Collision")
  {
    REQUIRE( f1.collision(f2) == 22 );
    REQUIRE( f2.collision(f1) == 11 );
    REQUIRE( f1.collision(f3) == 0 );
  }

  SECTION("Health, damage, invicibility")
  {
    REQUIRE(f1.getHealth() == 100);
    f1.getHit(10);
    REQUIRE(f1.getHealth() == 90);
    REQUIRE(f1.isDead() == 0);


    f1.heal(10);
    REQUIRE(f1.getHealth() == 100);

    f1.getHit(100);
    REQUIRE(f1.getHealth() == 0);
    REQUIRE(f1.isDead() == 1);

  }


}
