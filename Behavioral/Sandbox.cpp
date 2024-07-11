#include <iostream>
using namespace std;

// 하위 클래스 샌드박스
// 상위 클래스에서 정의한 알고리즘을 하위 클래스에서 구현하는 패턴

class Game{
    public:
        void play(){
             initialize();
             startPlay();
             endPlay();
        }

        virtual ~Game() {}

    protected:
        virtual void initialize() = 0;
        virtual void startPlay() = 0;
        virtual void endPlay() = 0;
};

class Football : public Game{
    protected:
        void initialize() override{
            cout << "Football Game Initialized! Start playing." << endl;
        }

        void startPlay() override{
            cout << "Football Game Started. Enjoy the game!" << endl;
        }

        void endPlay() override{
            cout << "Football Game Finished!" << endl;
        }
};

int main()
{
    Game* game = new Football();
    game->play();
    delete game;

}