//
// Created by mattia on 19/05/20.
//

#ifndef STEALTH_INVENTORY_H
#define STEALTH_INVENTORY_H


#include <SFML/Graphics.hpp>
#include <forward_list>

struct InventoryItem {
    int id;


    bool operator==(const struct InventoryItem& other) const {
        return other.id == this->id;
    }
};

class Inventory : public sf::Drawable, public sf::Transformable {
public:


protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::forward_list<std::pair<InventoryItem, int>> inventory;
};


#endif //STEALTH_INVENTORY_HPP
