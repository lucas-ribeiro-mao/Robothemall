#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H

#include <SFML/Graphics.hpp>

class Entity;
class Map;

class RendererInterface {
  public :
    virtual void displayEntity(const Entity& entity) =0;

};

#endif
