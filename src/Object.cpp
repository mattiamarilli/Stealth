//
// Created by vivedo on 11/05/20.
//

#include "Object.hpp"

Object::Object(std::shared_ptr<Tile> tile, sf::Vector2f position, ObjectProperties properties) : properties(
        properties) {
    this->tile = tile;
    this->position = position;
    this->properties.numberInInventory = 0;
}

Object::Object(std::shared_ptr<Object> obj) {
    this->properties = obj->properties;
    this->tile = obj->tile;
    this->position = obj->position;
}


//TODO remove all the code that generates rectangle for testing purpose
void Object::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (tile != nullptr && this->properties.id == 0) {
        tile->setPosition(position);
        target.draw(*tile);
    } else if (this->properties.numberInInventory != 0) {
        //if the object is in the inventory
        int red = 0;
        int green = 0;
        int blue = 0;
        switch (this->properties.id) {
            case 1:
                green = 255;
                break;
            case 2:
                red = 255;
                break;
            case 3:
                blue = 255;
                break;
            case 4:
                red = 255;
                blue = 150;
                break;
            default:
                break;
        }
        sf::RectangleShape rect({40, 40});
        rect.setFillColor(sf::Color(red, green, blue));
        rect.setPosition(target.getView().getCenter().x + 345,
                         target.getView().getCenter().y - 375 + ((this->properties.numberInInventory - 1) * 45));
        target.draw(rect);
    } else if (this->properties.id >= 1 && this->properties.id <= 4) {
        int red = 0;
        int green = 0;
        int blue = 0;
        switch (this->properties.id) {
            case 1:
                green = 255;
                break;
            case 2:
                red = 255;
                break;
            case 3:
                blue = 255;
                break;
            case 4:
                red = 255;
                blue = 150;
                break;
            default:
                break;
        }
        sf::RectangleShape rect({40, 40});
        rect.setFillColor(sf::Color(red, green, blue));

        rect.setPosition(this->position.x, this->position.y);
        target.draw(rect);
    }
    if (this->properties.destroyable == true) {
        sf::RectangleShape re({static_cast<float>(getHealth()) / 100 * 20, 2});
        re.setPosition({getPos().x - 5, getPos().y - 5});
        re.setFillColor(sf::Color::Red);

        target.draw(re);
    }

#ifdef STEALTH_GRAPHIC_DEBUG
    if(tile->collisionBox.height > 0 && tile->collisionBox.width > 0) {
        sf::RectangleShape cb(sf::Vector2f(tile->collisionBox.width, tile->collisionBox.height));
        cb.setPosition(position.x + tile->collisionBox.left, position.y + tile->collisionBox.top);
        cb.setFillColor(sf::Color(255, 127, 0, 127));
        target.draw(cb);
    }
#endif

}

bool Object::isDroppable(std::list<std::shared_ptr<Object>> &objects, sf::Vector2f playerPos) {
    for (auto &&obj : objects) {
        if (obj->properties.id == 1) //TODO sobstitute whit const value
            continue;
        if (obj->getAbsCollisionBox().contains(playerPos.x + this->tile->collisionBox.width,
                                               playerPos.y + this->tile->collisionBox.height))
            return false;
    }
    return true;
}

void Object::applayDamage(int damage) {
    if (properties.destroyable)
        this->setHealth(health - damage > 0 ? health - damage : 0);
}

bool Object::explode(std::list<std::shared_ptr<Object>> &objects) {
    if (this->properties.explosive) {
        for (auto &&o : objects) {
            if (o->properties.id == 1 &&
                MathHelper::distanceBetweenTwoPoints(o->getPos(), this->getPos()) < this->properties.explosionRadius) {
                o->applayDamage(this->properties.damage);
                return true;
            }
        }
    }
    return false;
}