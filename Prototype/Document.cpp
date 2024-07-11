#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 프로토타입 
// 다양한 유형의 문서를 생성하는 방법

class Document {
public:
    virtual ~Document() {}
    virtual Document* clone() const = 0;
    virtual void print() const = 0;
};

class Resume : public Document {
private:
    string content;
public:
    Resume() : content("This is a Resume") {}
    Resume(const Resume& other) : content(other.content) {}

    Document* clone() const override {
        return new Resume(*this);
    }

    void print() const override {
        cout << content << endl;
    }
};

class Report : public Document {
private:
    string content;
public:
    Report() : content("This is a Report") {}
    Report(const Report& other) : content(other.content) {}

    Document* clone() const override {
        return new Report(*this);
    }

    void print() const override {
        cout << content << endl;
    }
};

class DocumentManager {
private:
    unordered_map<string, Document*> prototypes;
public:
    ~DocumentManager() {
        for (auto& pair : prototypes) {
            delete pair.second;
        }
    }

    void addPrototype(const string& key, Document* prototype) {
        prototypes[key] = prototype;
    }

    Document* createDocument(const string& key) {
        return prototypes[key]->clone();
    }
};

int main() {
    DocumentManager docManager;
    docManager.addPrototype("resume", new Resume());
    docManager.addPrototype("report", new Report());

    Document* doc1 = docManager.createDocument("resume");
    Document* doc2 = docManager.createDocument("report");

    doc1->print(); // This is a Resume
    doc2->print(); // This is a Report

    delete doc1;
    delete doc2;

    return 0;
}