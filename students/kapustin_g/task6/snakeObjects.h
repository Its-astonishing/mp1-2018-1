#pragma once
#include <vector>
#include <ctime>
#define STARTBLOCKS 5

struct point
{
    short int x;
    short int y;
    point& operator =(const point& s)
    {
        x = s.x;
        y = s.y;
        return *this;
    }
    bool operator == (const point& s) const 
    {
        return x == s.x && y == s.y;
    }
    
};
class snakeObjects
{
    std::vector <point> snake;
    point apple;
    short int lastDirection = 3; // 1 - right, 2 - up, 3 - left, 4 - down 
    void createApple();
public:
    snakeObjects();
    point getHead() const;
    point getTail() const;
    std::vector <point>& getSnake();
    int move(short int direction); // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
    point getApple() const;
    bool isGameLost() const;
    short int size() const;
};