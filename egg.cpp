//
// Created by anorak on 22.12.2020.
//

#include "egg.h"

void Game::Draw(Snake snake) {

}

void Game::start()
{
    size.first=100;
    size.second=100;
    cout << "\e[8;"+to_string(size.first)+";"+to_string(size.second)+"t";

}

void Game::Posfruit() {
    srand(time(0));

}
void Point::set(int x, int y)
{
    coo.first=x;
    coo.second=y;

}

void Point::operator=(Point p) {
    this->coo.first=p.coo.first;
    this->coo.second=p.coo.second;
}

bool Point::operator!=(Point p) {
    if((this->coo.first!=p.coo.first)&&(this->coo.second!=p.coo.second))
        return true;
    return false;
}

bool Point::operator==(Point p) {
    if((this->coo.first==p.coo.first)&&(this->coo.second==p.coo.second))
        return true;
    return false;
}
