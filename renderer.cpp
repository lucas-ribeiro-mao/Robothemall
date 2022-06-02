#include "renderer_interface.hpp"
#include "renderer.hpp"
#include <iostream>
#include <typeinfo>



Renderer::Renderer(const int width, const int heigth)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, heigth), "Robothemall", sf::Style::Titlebar | sf::Style::Close);
    _window->clear(sf::Color::Black);
}

Renderer::~Renderer()
{
    delete _window;
}



void Renderer::waitForExit(sf::Event event)
{
  // check all the window's events that were triggered since the last iteration of the loop
  switch (event.type){
    // "close requested" event: we close the window
    case sf::Event::Closed:
      _window->close();
      break;
    case sf::Event::KeyPressed:
      if( event.key.code == sf::Keyboard::Escape)
        _window->close();
      break;
    default:
      break;
  }

}

//Display the map
void Renderer::render(const Map& map){
  _window->clear();
  map.display((*this));
  _window->display();
}

//display any entity on the map
void Renderer::displayEntity(const Entity& entity) {
  this->getWindow().draw(entity.getShape());
}


//display Character entity type
void Renderer::displayEntity(const Character& entity) {
  this->getWindow().draw(entity.getShape());
  this->getWindow().draw(*entity.getHealthBar()[0]);
  this->getWindow().draw(*entity.getHealthBar()[1]);
}
