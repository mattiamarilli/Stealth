//
// Created by vivedo on 09/05/20.
//

#ifndef STEALTH_SEEKSTRATEGY_HPP
#define STEALTH_SEEKSTRATEGY_HPP

#include <list>
#include <vector>
#include <cfloat>
#include <vector>
#include "Strategy.hpp"
#include "AStar.hpp"
#include "Object.hpp"
#include "Game.hpp"

class SeekStrategy : public Strategy {
public:
    sf::Vector2f getNextMove(GameObject &gameObject, Game &game) override;
    void addLocation(sf::Vector2i location);
    
private:
    std::vector<sf::Vector2i> locations;
    int currentTarget = 0;
    AStar *aStar;
};


#endif //STEALTH_SEEKSTRATEGY_HPP
