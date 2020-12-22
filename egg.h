#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

namespace fs = std::filesystem;
using namespace  std;
using coords=pair<int,int>;

class Point
{
    coords  coo;
    bool operator==(Point p);
    bool  operator!=(Point p);
    void operator =(Point p);
    void set(int x, int y);
    friend  class Game;
};

class Snake
{
    void Control();
    vector<Point> snakepos;
    void Move();
    void Eat();
    friend  class Game;
};

class Game
{
    pair<int,int>size;
    Point Fruit;

    void Posfruit();
    void start();
    void Draw(Snake snake);
    Snake sn;

};

void Snake::Control() {
    
}

