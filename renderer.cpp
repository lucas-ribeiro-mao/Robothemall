#include "renderer_interface.hpp"
#include "renderer.hpp"
#include <iostream>



Renderer::Renderer(const int width, const int heigth)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, heigth), "Fenêtre Jeu");
    _window->clear(sf::Color::Black);
}

Renderer::~Renderer()
{
    delete _window;
}



void Renderer::waitForExit()
{
    _window->display();

    std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;

    while (_window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _window->close();
        }
    }
}



void Renderer::displayEntity(const Entity& entity) {
  //TODO
  this->getWindow().draw(entity.getShape());
  getWindow().display();
}
