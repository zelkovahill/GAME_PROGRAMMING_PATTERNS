#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 행동 패턴은 객체  간의 상호작용을 캡슐화하여 시스템의 유연성과 확장성을 높인다.
// 하위 클래스 샌드박스 패턴은 상위 클래스에서 정의한 알고리즘을 하위 클래스에서 구현하는 패턴이다.
// 타입 객체 패턴은 객체의 타입을 클래스로 정의하여 동적으로 객체의 타입을 변경하거나 확장할 수 있다.

class Type{
    public: 
        virtual string getTypeName() const = 0;
};

class FireType : public Type{
    public:
        string getTypeName() const override{
            return "Fire";
        }
};

class WaterType : public Type{
    public:
        string getTypeName() const override{
            return "Water";
        }
};

class Pokemon{
    private:
        string name;
        Type* type;

    public:
        Pokemon(const string& name, Type* type) : name(name), type(type) {}

        void setType(Type* type){
            this->type = type;
        }

        void display() const{
            cout<< "Pokemon: " <<name<< ", Type: "<<type->getTypeName()<<"\n";
        }
};

int main(){
    FireType fire;
    WaterType water;

    Pokemon charmander("Charmander", &fire);
    charmander.display();

    charmander.setType(&water);
    charmander.display();

}
