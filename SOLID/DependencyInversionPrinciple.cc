#include <iostream>
#include <memory>

using namespace std;


class Switchable
{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual ~Switchable() = default;
};

class LightBulb : public Switchable
{
    public:
        void turnOn() override
        {
            cout<<"전구를 켭니다."<<"\n";
        }

        void turnOff() override
        {
            cout<<"전구를 끕니다."<<"\n";
        }
};

class Switch
{
    Switchable* device;

    public:
        Switch(Switchable* device) : device(device) {}

        void operate(bool on)
        {
            if(on)
            {
                device->turnOn();
            }
            else
            {
                device->turnOff();
            }
        }
};