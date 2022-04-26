#include "renderer_interface.hpp"
#include "renderer.hpp"
#include <iostream>



Renderer::Renderer(const int width, const int heigth)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, heigth), "Fenêtre Jeu", sf::Style::Titlebar | sf::Style::Close);
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
  }

}

void Renderer::render(const Map& map){
  _window->clear();
  //std::cout<<map.getEntityMap().size();
  map.display((*this));

  _window->display();
}

void Renderer::displayEntity(const Entity& entity) {
  //TODO
  //std::cout<<"bien ouej boss";
  this->getWindow().draw(entity.getShape());
}
