#include <iostream>
using namespace std;

// 명령 패턴의 주요 개념
// 명령 : 명령 인터페이스나 추상 클래스를 정의한다. 보통 execute()라는 메서드를 가진다.
// 구체적인 명령 : 명령 인터페이스를 구현한 클래스이다. 실제로 명령을 수행하는 로직이 들어간다.
// 수신자 : 명령이 수행될 대상이다. 실제 작업을 수행하는 객체다.
// 발행자 : 명령 객체를 저장하고, 명령을 호출하여 실행한다.
// 클라이언트 : 구체적인 명령 객체를 생성하고 발행자에게 할당한다.

// Command 인터페이스


class Command
{
    public:
        virtual ~Command(){}
        virtual void execute() = 0;
};

// 구체적인 Command 클래스
class JumpCommand : public Command
{
    public:
        void execute() override
        {
            // 점프하는 동작을 수행한다.
            cout<<"Jump!"<<"\n";
            
        }
};

class FireCommand : public Command
{
    public:
        void execute() override
        {
            // 발사하는 동작을 수행한다.
            cout<<"Fire!"<<"\n";
        }
};

// Invoker 클래스
class InputHandler
{
    private:
        Command* buttonX;
        Command* buttonY;


    public:
        void setCommandX(Command* command)
        {
            buttonX = command;
        }

        void setCommandY(Command* command)
        {
            buttonY = command;
        }

        void pressButtonX()
        {
            if(buttonX)
            {
                buttonX->execute();
            }
        }

        void pressButtonY()
        {
            if(buttonY)
            {
                buttonY->execute();
            }
        }
};


int main()
{
    InputHandler inputHandler;
    JumpCommand jumpCommand;
    FireCommand fireCommand;

    inputHandler.setCommandX(&jumpCommand);
    inputHandler.setCommandY(&fireCommand);

    inputHandler.pressButtonX();
    inputHandler.pressButtonY();

    return 0;
}

