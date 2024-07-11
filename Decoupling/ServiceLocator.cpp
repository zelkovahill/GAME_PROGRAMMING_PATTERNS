#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

class Service {
public:
    virtual void execute() = 0;
};

class ConcreteServiceA : public Service {
public:
    void execute() override {
        cout << "Executing Service A" << endl;
    }
};

class ConcreteServiceB : public Service {
public:
    void execute() override {
        cout << "Executing Service B" << endl;
    }
};

class ServiceLocator {
private:
    unordered_map<string, Service*> services;

public:
    void registerService(const string& name, Service* service) {
        services[name] = service;
    }

    Service* getService(const string& name) {
        return services[name];
    }

    ~ServiceLocator() {
        for (auto& pair : services) {
            delete pair.second;
        }
    }
};

int main() {
    ServiceLocator serviceLocator;

    serviceLocator.registerService("ServiceA", new ConcreteServiceA());
    serviceLocator.registerService("ServiceB", new ConcreteServiceB());

    Service* serviceA = serviceLocator.getService("ServiceA");
    serviceA->execute(); // Executing Service A

    Service* serviceB = serviceLocator.getService("ServiceB");
    serviceB->execute(); // Executing Service B

    return 0;
}