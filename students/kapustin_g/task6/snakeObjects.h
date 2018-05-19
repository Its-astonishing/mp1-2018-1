#pragma once
#include <vector>
#include <ctime>
#define STARTBLOCKS 5

struct point
{
    short int x;
    short int y;
    point& operator =(const point& s);
    bool operator == (const point& s) const;
};

class snakeObjects
{
    point fieldSize;
    std::vector <point> snake;
    point apple;
    short int lastDirection = 3; // 1 - right, 2 - up, 3 - left, 4 - down 
    void createApple();
public:
    snakeObjects();
    void setFieldSize(short int fieldSizeX, short int fieldSizeY);
    void init();
    point getHead() const;
    point getTail() const;
    std::vector <point>& getSnake();
    int move(short int direction); // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
    point getApple() const;
    bool headAteTale() const;
    short int size() const;
};