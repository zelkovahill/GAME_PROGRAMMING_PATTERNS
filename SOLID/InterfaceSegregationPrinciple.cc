#include <iostream>

using namespace std;

class Flyable
{
    public:
        virtual void fly() = 0;
        virtual ~Flyable() = default;
};

class Swimmable
{
    public:
        virtual void swim() = 0;
        virtual ~Swimmable() = default;
};

class Bird : public Flyable
{
    public:
        void fly() override
        {
            cout<<"새가 날아갑니다."<<"\n";
        }
};


class Fish : public Swimmable
{
    public:
        void swim() override
        {
            cout<<"물고기가 헤엄칩니다."<<"\n";
        }
};

