#include <iostream>
using namespace std;

// 더티 플래그
// 객체의 상태가 변경되었을 때 플래그를 설정하여, 필요한 경우에만
// 재계산이나 업데이트를 수행하는 패턴이다.
// 이를 통해 불필요한 계산을 줄이고 성능을 향상시킬 수 있다.

class GameObject {
private:
    bool isDirty;
    int position; 
    int cachedValue;

public:
    GameObject() : isDirty(true), position(0), cachedValue(0) {}

    void setPosition(int newPosition) {
        position = newPosition;
        isDirty = true;
    }

    int getValue() {
        if (isDirty) {
            cachedValue = calculateValue();
            isDirty = false;
        }
        return cachedValue;
    }

private:
    int calculateValue() {
        // Complex calculation based on position
        return position * 2;
    }
};

int main() {
    GameObject obj;
    obj.setPosition(10);
    cout << "Value: " << obj.getValue() << endl; // Recalculate
    cout << "Value: " << obj.getValue() << endl; // Use cached value

    return 0;
}