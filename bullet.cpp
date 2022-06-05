#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f position, float speed, sf::Vector2f direction) : Entity() {
  _speed = speed;
  _position=position;
  _damage = BULLET_DAMAGE;

  _type="Bullet";

  _hitbox = sf::RectangleShape(sf::Vector2f(BULLET_SIZE,BULLET_SIZE));
  _hitbox.setPosition(position);
  _hitbox.setFillColor(sf::Color::Blue);

  _shape = sf::RectangleShape(sf::Vector2f(BULLET_SIZE,BULLET_SIZE));
  _shape.setPosition(position);
  _shape.setFillColor(sf::Color::Blue);
  _direction=direction;
}


void Bullet::move(sf::Event& event, sf::Time& dt, Map& map){
  // angle between player and foes to determine the direction
  double angle = atan2(_direction.y, _direction.x);

  _velocity.x = _speed*dt.asSeconds()*cos(angle);
  _velocity.y = _speed*dt.asSeconds()*sin(angle);

  _position+=_velocity;
  updatePosition();
}
