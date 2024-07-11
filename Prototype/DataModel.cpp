#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 데이터 모델링에서 프로토타입 패턴을 사용하여 데이터 구조를 정의
// 이를 복제하여 다양한 데이터 인스턴스를 생성할 수 있다.
// 이는 특히 복잡한 데이터구조를 반복적으로 생성해야 하는 경우에 유용하다.

class DataModel {
public:
    virtual ~DataModel() {}
    virtual DataModel* clone() const = 0;
    virtual void display() const = 0;
};

class UserModel : public DataModel {
private:
    string name;
    int age;
public:
    UserModel(const string& name, int age) : name(name), age(age) {}
    UserModel(const UserModel& other) : name(other.name), age(other.age) {}

    DataModel* clone() const override {
        return new UserModel(*this);
    }

    void display() const override {
        cout << "User: " << name << ", Age: " << age << endl;
    }
};

class DataManager {
private:
    vector<DataModel*> models;
public:
    ~DataManager() {
        for (auto model : models) {
            delete model;
        }
    }

    void addModel(DataModel* model) {
        models.push_back(model->clone());
    }

    void displayModels() const {
        for (auto model : models) {
            model->display();
        }
    }
};

int main() {
    DataManager dataManager;

    UserModel user1("Alice", 30);
    UserModel user2("Bob", 25);

    dataManager.addModel(&user1);
    dataManager.addModel(&user2);

    dataManager.displayModels();

    return 0;
}