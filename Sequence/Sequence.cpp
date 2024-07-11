#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

// 간단한 게임 루프와 업데이트 로직을 구현한 코드

class GameObject{
    public:
        virtual void update() =0;
        virtual void render() = 0;
};

class Player : public GameObject{
    private:
        int x;
        int y;

    public:
        Player(int x, int y) : x(x), y(y) {}

        void update() override{
            // 플레이어 상태 업데이트 로직
            x+=1;   // 예 : 오른쪽으로 이동
        }

        void render() override{
            // 플레이어 그리기 로직
            cout<< "Player at (" << x << ", " << y << ")" << endl;
        }
};

class Game{
    private:
        bool running;
        vector<GameObject*> gameObjects;

    public:
        Game() : running(false) {}

        void addGameObject(GameObject* obj){
            gameObjects.push_back(obj);
        }

        void run(){
            running = true;
            while(running){
                auto start = chrono::high_resolution_clock::now();

                // 입력 처리 (예제에서는 생략)

                // 게임 상태 업데이트
                for(auto obj : gameObjects){
                    obj->update();
                }

                // 이중 버퍼링을 사용한 화면 그리기
                system("clear");
                for(auto obj : gameObjects){
                    obj->render();
                }

                //  프레임 제어 (60fps 기준)
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                this_thread::sleep_for(chrono::milliseconds(16) - elapsed);
            }
        }

        void stop(){
            running = false;
        }

};

// 위 코드를 실행하면 x 좌표가 1씩 증가하면서 플레이어가 오른쪽으로 이동하는 것을 볼 수 있다. 
// 취소하려면 cmd + C를 누르면 된다.
int main()
{
    Game game;

    Player player(0,0);

    game.addGameObject(&player);

    game.run();

    return 0;
}