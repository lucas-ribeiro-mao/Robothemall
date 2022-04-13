#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_interface.hpp"
#include "entity.hpp"


class Renderer : public RendererInterface{
  protected :
    sf::RenderWindow* _window;
  public :

    Renderer(const int width, const int heigth);
    ~Renderer();

    void waitForExit();

    sf::RenderWindow& getWindow() {return *_window;};

    void displayEntity(const Entity& entity);

};

#endif
