//
// Created by vivedo on 09/05/20.
//

#ifndef STEALTH_GAMEOBJECT_HPP
#define STEALTH_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>
#include "Tile.hpp"

class GameObject : public sf::Drawable, public sf::Transformable {
public:
    GameObject() = default;
    GameObject(std::shared_ptr<Tile> tile, sf::Vector2f position);
    virtual ~GameObject() override {};
    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f pos);
    void setPos(int x, int y);
    int getHealth() const;
    void setHealth(int h);

    sf::Vector2f getAbsDrawingCenter();
    sf::FloatRect getAbsCollisionBox();


    // TODO: make tile private and add getters for collision boxes
    std::shared_ptr<Tile> tile;

protected:
    sf::Vector2f position = {0, 0};
    unsigned int health = 100;


};


#endif //STEALTH_GAMEOBJECT_HPP
