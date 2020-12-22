#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
using namespace sf;
namespace fs = std::filesystem;
using namespace  std;
/*using coords=pair<int,int>;

class Point
{
    coords  coo;
    bool operator==(Point p);
    bool  operator!=(Point p);
    void operator =(Point p);
    void set(int x, int y);
    friend  class Game;
    friend class Snake;
};

class Snake
{
    void moove();
    Snake(int x, int y, int len);
    enum D{Up,Down,Left,Right,Stop};
    D mv;
    void Control();
    vector<Point> snakepos;
    void Move(D d);
    bool Eat(Point F);
    pair<int,int>Size;
    friend  class Game;
};

class Game
{
    pair<int,int>Size;
    Point Fruit;
public:
    void Posfruit();
    void start();
    void Draw();
    Snake* sn;
    friend class Snake;
    void Play();
};*/


