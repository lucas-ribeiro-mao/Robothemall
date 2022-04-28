#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_interface.hpp"
#include "entity.hpp"
#include "character.hpp"
#include "map.hpp"

class Renderer : public RendererInterface{
  protected :
    sf::RenderWindow* _window;
  public :

    Renderer(const int width, const int heigth);
    ~Renderer();

    void waitForExit(sf::Event event);

    void render(const Map& map);

    void displayEntity(const Entity& entity);
    void displayEntity(const Character& entity) ;


    // ACCESSEURS
    bool getIsOpen(){ return _window->isOpen();}

    sf::RenderWindow& getWindow() {return *_window;};

};

#endif
