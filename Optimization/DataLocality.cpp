#include <iostream>
#include <vector>
using namespace std;

// 데이터 지역성
// 프로그램의 데이터가 메모리 내에서 서로 가까운 위치에 저장되어 접근 시간과
// 캐시 효율성을 향상시키는 패턴

// 이를 통해 CPU 캐시 히트를 증가시키고 메모리 접근 시간을 줄일 수 있다.

class Particle {
public:
    float x, y, z;  // Position
    float vx, vy, vz;  // Velocity
};

void updateParticles(vector<Particle>& particles) {
    for (Particle& p : particles) {
        p.x += p.vx;
        p.y += p.vy;
        p.z += p.vz;
    }
}

int main() {
    vector<Particle> particles(1000);
    // Initialize particles...

    updateParticles(particles);
    return 0;
}