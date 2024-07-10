#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 플라이급 클래스 : 나무의 공토 속성을 저장 (이름, 색상, 질감)
// 플라이급 팩토리 클래스 : 나무의 타입을 관리하고, 이미 존재하는 타입을 재사용하여 메모리 사용량을 줄인다.
// 클라이언트 클래스 : 나무 객체를 생성하고, 나무의 타입을 플라이급 팩토리로부터 받아온다.
// 클라이언트 코드 : 숲을 생성하고, 나무를 심는다.

// 나무 타입을 공유하여 메모리 사용량을 줄이고 성능을 향상시켰다.
// 수천 개의 나무를 심더라도 각 나무 타입은 하나의 객체만 생성되므로 메모리 효율성이 크게 항상된다.


// 플라이급 클래스(나무)
class TreeType
{
    public:
        string name;
        string color;
        string texture;
        
        TreeType(string name, string color, string texture) : name(name), color(color), texture(texture){}

        void display(int x, int y)
        {
            cout<<"Tree: "<<name<<"("<<x<<", "<<y<<")"<<"\n";
            cout<<"Color: "<<color<<"\n";
            cout<<"Texture: "<<texture<<"\n";
        }
};

// 플라이급 팩토리 클래스
class TreeFactory
{
    private:
        unordered_map<string, TreeType*> treeTypes;

    public:
        TreeType* getTreeType(string name, string color, string texture)
        {
            string key = name + " " + color + " " + texture;
            if(treeTypes.find(key)==treeTypes.end())
            {
                treeTypes[key] = new TreeType(name, color, texture);
            }
            return treeTypes[key];
        }

        ~TreeFactory()
        {
            for(auto& pair : treeTypes)
            {
                delete pair.second;
            }
        }

};

// 클라이언트 클래스 (나무 객체)
class Tree
{
    private:
        int x;
        int y;
        TreeType* type;

    public:
        Tree(int x, int y, TreeType* type) : x(x), y(y), type(type){}

        void display()
        {
            type->display(x, y);
        }
};

// 클라이언트 코드(숲)
class Forest
{
    private:
        vector<Tree> trees;
        TreeFactory treeFactory;

    public:
        void PlantTree(int x, int y, string name, string color, string texture)
        {
            TreeType* type = treeFactory.getTreeType(name, color, texture);
            trees.emplace_back(x, y, type);
        }

        void display()
        {
            for(auto& tree : trees)
            {
                tree.display();
            }
        }
};

int main()
{
    Forest forest;
    forest.PlantTree(1, 2, "Pine", "Green", "Rough");
    forest.PlantTree(3, 4, "Oak", "Brown", "Smooth");

    forest.display();
}