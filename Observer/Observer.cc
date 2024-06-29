#include <iostream>
#include <vector>

using namespace std;

//  IObservable (관찰 대상)  클래스
class IObservable
{
    public:
        virtual void AddObserver(class IObserver* observer) = 0;
        virtual void RemoveObserver(class IObserver* observer) = 0;
        virtual void NotifyObservers() = 0;
};

// IObserver (관찰자) 클래스
class IObserver
{
    public:
        virtual void Update() = 0;
};


// Person 클래스 (관찰 대상)
class Person : public IObservable
{
    private:
        int age;
        vector<IObserver*> observers;

    public:
        void SetAge(int newAge)
        {
            age=newAge;
            NotifyObservers();
        }

        void AddObserver(IObserver* observer) override
        {
            observers.push_back(observer);
        }

        void RemoveObserver(IObserver* observer) override
        {
            // 구현 생략
        }

        void NotifyObservers() override
        {
            for(IObserver* observer : observers)
            {
                observer->Update();
            }
        }

};

// UI 클래스 (관찰자)
class UI : public IObserver
{
    public:
        void Update() override
        {
            cout<<"UI : Person의 나이가 변경되었습니다."<<endl;
        }
};

int main()
{
    Person person;
    UI ui;

    person.AddObserver(&ui);

    // Person의 나이가 변경되면 UI가 알 수 있음
    person.SetAge(30);
}