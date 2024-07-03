#include <iostream>
#include <string>

using namespace std;

// 상태를 나타내는 열거형 
enum class State
{
    Closed,
    Open,
    Locked
};

// FSM 클래스
class DoorStateMachine
{
    private:
        State currentState;

    public:
        DoorStateMachine() : currentState(State::Closed){}

        void handleEvent(const string& evevt)
        {
            switch(currentState)
            {
                case State::Closed:
                    if(evevt =="open")
                    {
                        currentState = State::Open;
                        cout<<"문이 열렸습니다."<<"\n";
                    }
                    else if(evevt == "lock")
                    {
                        currentState = State::Locked;
                        cout<<"문이 잠겼습니다."<<"\n";
                    }
                    else
                    {
                        cout<<"잘못된 이벤트입니다."<<"\n";
                    }
                    break;

                case State::Open:
                    if(evevt == "close")
                    {
                        currentState = State::Closed;
                        cout<<"문이 닫혔습니다."<<"\n";
                    }
                    else
                    {
                        cout<<"잘못된 이벤트입니다."<<"\n";
                    }
                    break;

                case State::Locked:
                    if(evevt == "unlock")
                    {
                        currentState = State::Closed;
                        cout<<"문이 열렸습니다."<<"\n";
                    }
                    else
                    {
                        cout<<"잘못된 이벤트입니다."<<"\n";
                    }
                    break;

                default:
                    cout<<"잘못된 상태입니다."<<"\n";
                    break;
            }
        }

        string getCurrentState() const 
        {
            switch(currentState)
            {
                case State::Closed:
                    return "Closed";
                case State::Open:
                    return "Open";
                case State::Locked:
                    return "Locked";
                default:
                    return "Unknown";
            }
        }
};

int main()
{
    DoorStateMachine door;

    cout << "현재 문의 상태 : " <<door.getCurrentState()<<"\n";

    door.handleEvent("open");
    cout << "현재 문의 상태 : " <<door.getCurrentState()<<"\n";

    door.handleEvent("close");
    cout << "현재 문의 상태 : " <<door.getCurrentState()<<"\n";

    door.handleEvent("lock");
    cout << "현재 문의 상태 : " <<door.getCurrentState()<<"\n";

     door.handleEvent("unlock");
    cout << "현재 문의 상태 : " <<door.getCurrentState()<<"\n";
}