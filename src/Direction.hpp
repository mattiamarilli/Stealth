//
// Created by vivedo on 23/07/20.
//

#ifndef STEALTH_DIRECTION_HPP
#define STEALTH_DIRECTION_HPP


#include <SFML/Graphics.hpp>

class Direction {
public:
    enum Directions {
        NORTH,
        NORTH_EAST,
        EAST,
        SUD_EAST,
        SUD,
        SUD_OVEST,
        OVEST,
        NORTH_OVEST
    };

    Direction() = default;

    constexpr explicit Direction(Directions dir) : dir(dir) {}

    explicit Direction(sf::Vector2f &vect) {
        if (vect.x > 0)
            if (vect.y == 0) dir = Directions::EAST;
            else if (vect.y > 0) dir = Directions::SUD_EAST;
            else dir = Directions::NORTH_EAST;
        else if (vect.x == 0)
            if (vect.y > 0) dir = Directions::SUD;
            else dir = Directions::NORTH;
        else if (vect.x < 0)
                if(vect.y > 0) dir = Directions::SUD_OVEST;
                else if (vect.y == 0) dir = Directions::OVEST;
                else dir = Directions::NORTH_OVEST;
    }

    operator Directions() const { return dir; }

    explicit operator bool() = delete;

private:
    Directions dir;
};


#endif //STEALTH_DIRECTION_HPP
