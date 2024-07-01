#include <iostream>

using namespace std;

class Bird
{
    public:
        virtual void move()
        {
            cout<<"새가 날아갑니다."<<"\n";
        }
};

class Sparrow : public Bird
{
    public:
        void move() override
        {
            cout<<"참새가 날아갑니다."<<"\n";
        }
};

class Penguin : public Bird
{
    public:
        void move() override
        {
            cout<<"펭귄이 수영합니다."<<"\n";
        }
};