#include <iostream>
#include <vector>
using namespace std;

// 객체 풀
// 객체를 미리 생성해 두고 필요할 때 재사용하는 패턴
// 이를통해 객체 생성과 소멸에 따른 오버헤드를 줄이고 성능을 향상시킬 수 있다.

class GameObject {
public:
    void reset() {
        // Reset object state
    }
};

class ObjectPool {
private:
    vector<GameObject*> pool;

public:
    ~ObjectPool() {
        for (auto obj : pool) {
            delete obj;
        }
    }

    GameObject* acquire() {
        if (pool.empty()) {
            return new GameObject();
        } else {
            GameObject* obj = pool.back();
            pool.pop_back();
            return obj;
        }
    }

    void release(GameObject* obj) {
        obj->reset();
        pool.push_back(obj);
    }
};

int main() {
    ObjectPool pool;

    GameObject* obj1 = pool.acquire();
    pool.release(obj1);

    GameObject* obj2 = pool.acquire();  // Reuse obj1
    return 0;
}