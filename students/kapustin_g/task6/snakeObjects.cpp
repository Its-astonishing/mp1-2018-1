#include "snakeObjects.h"

point& point::operator =(const point& s)
{
    x = s.x;
    y = s.y;
    return *this;
}
bool point::operator == (const point& s) const
{
    return x == s.x && y == s.y;
}
void snakeObjects::createApple()
{
    bool i = 1;
    srand(time(0));
    while(i)
    {
        apple.x = 2 + rand() % (fieldSize.x-3);
        apple.y = 2 + rand() % (fieldSize.y-3);
        bool flag = 1;
        for (int j = 0; j < snake.size() && flag; j++)
        {
            if (snake[j] == apple)
                flag = 0;
        }
        if (flag)
            i = 0;
    }
}
snakeObjects::snakeObjects()
{ }
void snakeObjects::setFieldSize(short int fieldSizeX, short int fieldSizeY)
{
    fieldSize.x = fieldSizeX;
    fieldSize.y = fieldSizeY;
}
void snakeObjects::init()
{
    point part;
    part.x = fieldSize.x / 2;
    part.y = fieldSize.y / 2;
    snake.push_back(part);
    for (int i = 0; i < STARTBLOCKS - 1; i++)
    {
        part.x++;
        snake.push_back(part);
    }
    createApple();
}

point snakeObjects::getHead() const
{
    return snake[0];
}
point snakeObjects::getTail() const
{
    return snake[snake.size() - 1];
}
std::vector <point>& snakeObjects::getSnake()
{
    return snake;
}
int snakeObjects::move(short int direction)       // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
{
    int k = 1;
    if (lastDirection + 2 == direction || lastDirection - 2 == direction)
        direction = lastDirection;
    point tmp1 = snake[0]; 
    switch (direction) 
    {
    case 1:
        snake[0].x++;
        break;
    case 2:
        snake[0].y--;
        break;
    case 3:
        snake[0].x--;
        break;
    case 4:
        snake[0].y++;
        break;
    }
    if (snake[0].x == 1 || snake[0].x == fieldSize.x - 1 || snake[0].y == 1 || snake[0].y == fieldSize.y - 1)
        return 0;
    point tmp2 = tmp1;
    for (int i = 1; i < snake.size(); i++)
    {
        tmp2 = snake[i]; 
        snake[i] = tmp1; 
        tmp1 = tmp2;
    }
    if (snake[0] == apple)
    {
        k = 2;
        snake.push_back(tmp1);
        createApple();
    }

    lastDirection = direction;
    return k;
}
point snakeObjects::getApple() const
{
    return apple;
}
bool snakeObjects::headAteTale() const
{
    for (int i = 1; i < snake.size(); i++)
    {
        if (snake[0] == snake[i])
            return 1;
    }
    return 0;
}
short int snakeObjects::size() const
{
    return snake.size();
}