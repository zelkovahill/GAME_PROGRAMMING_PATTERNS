#include <iostream>
using namespace std;

// 실행취소와 재실행
// 명령 패턴은 실행취소(Undo)와 재실행(Redo) 기능을 쉽게 구현할 수 있다.
// 이를 위해 명령 객체는 실행된 명령을 저장하고, 실행취소와 재실행을 위한 메서드를 추가로 구현할 수 있다.


class Actor
{
    private:
        int x;
        int y;

    public:
        Actor() : x(0), y(0){}  // 초기 위치 (0, 0)

        void moveTo(int x, int y)
        {
            cout<<"Move to ("<<x<<", "<<y<<")"<<"\n";
        }

        void attack()
        {
            cout<<"Attack!"<<"\n";
        }

        int getX() const
        {
            return x;
        }
        int getY() const
        {
            return y;
        }




        
};

// Command 인터페이스 확장
class Command
{
    public:
        virtual ~Command(){}
        virtual void execute() =0;
        virtual void undo() = 0;
};

// 구체적인 Command 클래스
class MoveCommand : public Command
{
    private:
        Actor* actor;
        int x;
        int y;
        int prevX;
        int prevY;

        public:
            MoveCommand(Actor* actor, int x, int y) : actor(actor), x(x), y(y)
            {
                prevX = actor->getX();
                prevY = actor->getY();
            }

            void execute() override
            {
                actor->moveTo(x, y);
            }

            void undo() override
            {
                actor->moveTo(prevX, prevY);
            }

};

class AttackCommand : public Command
{
    private:
        Actor* actor;

    public:
        AttackCommand(Actor* actor) : actor(actor){}

        void execute() override
        {
            actor->attack();
        }

        void undo() override
        {
            cout<<"Cannot undo attack command"<<"\n";
        }
};

int main()
{
    Actor actor;
    MoveCommand moveCommand(&actor, 10, 20);
    AttackCommand attackCommand(&actor);

    moveCommand.execute();  // Move to (10, 20)
    moveCommand.undo();   // Move to (0, 0)

    attackCommand.execute(); // Attack!
    attackCommand.undo();   // Cannot undo attack command


}