//
// Created by mattia on 10/05/20.
//

#include "AStar.hpp"

std::vector<Node> AStar::getPath(Node hunter, Node dest) {

    std::vector<Node> empty;
    if (!isValid(dest.x, dest.y)) {
        //Destination is an obstacle;
        return empty;
    }
    if (isDestination(hunter.x, hunter.y, dest)) {
        //You are the destination
        return empty;
    }

    bool **closedList;
    closedList = new bool *[mapSize.x];
    for ( int i = 0; i < mapSize.x; i++ ) closedList[i] = new bool[mapSize.y];

    Node **allMap;
    allMap = new Node *[mapSize.x];
    for ( int i = 0; i < mapSize.x; i++ ) allMap[i] = new Node[mapSize.y];

    for (int x = 0; x < (15); x++) {
        for (int y = 0; y < (15); y++) {
            allMap[x][y].fCost = FLT_MAX;
            allMap[x][y].gCost = FLT_MAX;
            allMap[x][y].hCost = FLT_MAX;
            allMap[x][y].parentX = -1;
            allMap[x][y].parentY = -1;
            allMap[x][y].x = x;
            allMap[x][y].y = y;

            closedList[x][y] = false;
        }
    }

    //Initialize our starting list
    int x = hunter.x;
    int y = hunter.y;
    allMap[x][y].fCost = 0.0;
    allMap[x][y].gCost = 0.0;
    allMap[x][y].hCost = 0.0;
    allMap[x][y].parentX = x;
    allMap[x][y].parentY = y;

    std::vector<Node> openList;
    openList.emplace_back(allMap[x][y]);
    bool destinationFound = false;


    //return std::vector<Node>();
}

bool AStar::isDestination(int x, int y, Node dest) {
    return x == dest.x && y == dest.y;
}

bool AStar::isValid(int x, int y) {

    for ( auto it = obstacles->begin(); it != obstacles->end(); ++it )
    {
        if(x < (it->left + it->width) && x > it->left && y < it->top && y > (it->top - it->height))
            return false;
    }
    return true;
}

AStar::AStar(std::forward_list<Obstacle> &obs, sf::Vector2<unsigned int> mSize): obstacles(&obs), mapSize(mSize){

}



