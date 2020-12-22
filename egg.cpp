//
// Created by anorak on 22.12.2020.
//
/*
#include "egg.h"

void Game::Draw() {
    bool snk=0;
    for(int j=0;j<Size.first;j++)
    {
        for(int i=0;i<Size.second;i++)
        {
            if((i==(0||Size.first))||(j==(0||Size.second)))
                cout<<"*";
            else if(i==Fruit.coo.first && j==Fruit.coo.second)
                cout<<"f";
            else
                for(int s=0;s<sn->snakepos.size();s++)
                {
                    if(i==sn->snakepos[s].coo.first && j==sn->snakepos[s].coo.second) {
                        cout << "s";
                        snk=1;
                    }
                }
                if(snk==1)
                    snk=0;
                else
                    cout<<" ";
        }
        cout<<endl;
    }
}

void Game::start()
{
    Size.first=100;
    Size.second=100;
    cout << "\e[8;"+to_string(Size.first)+";"+to_string(Size.second)+"t";
    sn = new Snake(50,50,3);

}

void Game::Posfruit() {
    srand(time(0));
    bool ok=0;
    while(!ok) {
        ok=1;
        Fruit.set(rand() % Size.first + 1,rand() % Size.second + 1);
        for(int i=0;i<sn->snakepos.size();i++)
            if(sn->snakepos[i]==Fruit)
                ok=0;
    }

}

void Game::Play() {
    while(1)
    {
        Posfruit();
        Draw();
        sn->Control();
        sn->moove();
        if(sn->Eat(Fruit))
            Posfruit();
    }
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

void Snake::Control()
{
    if (Keyboard::isKeyPressed(Keyboard::Left)) { if (mv != Right)mv = Left; }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) { if ((mv != Left) && (mv != Stop))mv = Right; }
    else if (Keyboard::isKeyPressed(Keyboard::Up)) { if (mv != Down)mv = Up; }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) { if (mv != Up)mv = Down; }
    else if ((Keyboard::isKeyPressed(Keyboard::Left) && (Keyboard::isKeyPressed(Keyboard::Down)))) { if ((mv != Right) && (mv != Up))Move(Left); Move(Down); }
    else if ((Keyboard::isKeyPressed(Keyboard::Left) && (Keyboard::isKeyPressed(Keyboard::Up)))) { if ((mv != Right) && (mv != Down))Move(Left); Move(Up); }
    else if ((Keyboard::isKeyPressed(Keyboard::Right) && (Keyboard::isKeyPressed(Keyboard::Down)))) { if ((mv != Left) && (mv != Up))Move(Right); Move(Down); }
    else if ((Keyboard::isKeyPressed(Keyboard::Right) && (Keyboard::isKeyPressed(Keyboard::Up)))) { if ((mv != Left) && (mv != Down))Move(Right); Move(Up); }
    else if (Keyboard::isKeyPressed(Keyboard::P)) { mv = Stop; }
}

void Snake::Move(D d) {
    if(d!=Stop) {
        for (int i = 1; i < snakepos.size(); i++)
            snakepos[i] = snakepos[i - 1];
        switch (d) {
            case Right:
                snakepos[0].coo.first++;
            case Left:
                snakepos[0].coo.first--;
            case Up:
                snakepos[0].coo.second++;
            case Down:
                snakepos[0].coo.second--;
        }
        if(snakepos[0].coo.first==0)
            snakepos[0].coo.first=Size.first-1;
        if(snakepos[0].coo.first==Size.first)
            snakepos[0].coo.first=1;
        if(snakepos[0].coo.second==0)
            snakepos[0].coo.second=Size.second-1;
        if(snakepos[0].coo.second==Size.second)
            snakepos[0].coo.first=1;
    }
}

bool Snake::Eat(Point F) {
    if(F==snakepos[0]) {
        snakepos.push_back(Point());
        Move(mv);
        return 1;
    }
    return 0;
}

Snake::Snake(int x, int y, int len) {
    snakepos.clear();
    this->snakepos[0].set(x,y);
    for(int i=1;i<snakepos.size();i++) {
        snakepos[i].set(snakepos[i-1].coo.first+1,snakepos[i-1].coo.second);
    }
}

void Snake::moove() {
    Move(mv);
}*/
