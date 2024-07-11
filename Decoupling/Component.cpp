#include <iostream>
#include <vector>
using namespace std;

// 컴포넌트 
// 컴포넌트 패턴은 시스템의 기능을 독립적인 컴포넌트로 분리하여 
// 재사용성과 유연성을 높이는 패턴이다.
// 각 컴포넌트는 특정 기능을 담당
// 다른 컴포넌트와 독립적으로 동작할 수 있다.
// 이를 통해 코드의 모듈화를 촉진하고,
// 시스템의 유지보수성을 높일 수 있다.

class Component {
    public:
        virtual void update() = 0;
};

class RenderComponent : public Component{
    public:
        void update() override{
            cout << "Render Component Update" << endl;
        }
};

class PhysicsComponent : public Component{
    public:
        void update() override{
            cout << "Physics Component Update" << endl;
        }
};

class GameObject{
    private:
        vector<Component*> components;

        public:
            void addComponent(Component* component){
                components.push_back(component);
            }

            void update(){
                for(auto component : components){
                    component->update();
                }
            }
};

int main(){
    GameObject obj;
    obj.addComponent(new RenderComponent());
    obj.addComponent(new PhysicsComponent());

    obj.update();
}
