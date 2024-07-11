#include <iostream>
#include <vector>
using namespace std;

class GameObject {
public:
    float x, y;  // Position
    // Other properties...
};

class Grid {
private:
    int width, height, cellSize;
    vector<vector<vector<GameObject*>>> cells;

public:
    Grid(int width, int height, int cellSize) 
        : width(width), height(height), cellSize(cellSize) {
        cells.resize(width / cellSize);
        for (auto& column : cells) {
            column.resize(height / cellSize);
        }
    }

    void addObject(GameObject* obj) {
        int cellX = obj->x / cellSize;
        int cellY = obj->y / cellSize;
        cells[cellX][cellY].push_back(obj);
    }

    vector<GameObject*> getNearbyObjects(GameObject* obj) {
        int cellX = obj->x / cellSize;
        int cellY = obj->y / cellSize;
        return cells[cellX][cellY];
    }
};

int main() {
    Grid grid(100, 100, 10);
    GameObject obj1 = {5, 5};
    GameObject obj2 = {15, 15};

    grid.addObject(&obj1);
    grid.addObject(&obj2);

    vector<GameObject*> nearby = grid.getNearbyObjects(&obj1);
    cout << "Nearby objects: " << nearby.size() << endl;

    return 0;
}