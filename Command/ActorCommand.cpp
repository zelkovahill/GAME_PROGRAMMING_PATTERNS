#include <iostream>
using namespace std;

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};


// 액터에게 독점 행동을 지시할 때도 명령 패턴을 사용할 수 있다.
// 액터는 수신자롤 작동하고, 명령 객체는 액터의 특정 행동을 수행한다

// Receiver 클래스
class Actor
{
    public:
        void moveTo(int x, int y)
        {
            cout<<"Move to ("<<x<<", "<<y<<")"<<"\n";
        }

        void attack()
        {
            cout<<"Attack!"<<"\n";
        }
};

class MoveCommand : public Command
{
    private:
        Actor* actor;
        int x;
        int y;

        public:
            MoveCommand(Actor* actor, int x, int y) : actor(actor), x(x), y(y){}

            void execute() override
            {
                actor->moveTo(x, y);
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

};

int main()
{
    Actor actor;
    MoveCommand move(&actor, 10, 20);
    AttackCommand attack(&actor);

    move.execute();
    attack.execute();

    return 0;
}
