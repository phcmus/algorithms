#include <cwchar>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

#define MAX_DISTANCES 99999

using namespace std;

string filename = "input_3.txt";
int n = 0;
vector<vector<int>> map;
vector<int> path;
vector<vector<int>> hamiltonian_result = vector<vector<int>>(0);

bool isReadFile(string filename, int &n) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        inputfile >> n;

        map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        while (!inputfile.eof()) {
            int x = 0;
            int y = 0;
            int d = 0;
            inputfile >> x;
            inputfile >> y;
            inputfile >> d;
            if (x == -1 || y == -1 || d == -1)
                break;

            map[x][y] = d;
            map[y][x] = d;
        }

        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void printArray(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
}

void printMap(vector<vector<int>> arr, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool promising(int pos, int v) {
    // cout << "promising pos = " << pos << " v = " << v << endl;
    if (pos == n &&
        map[v][path[1]] == 0) // đỉnh cuối cùng và không có đường đi về 1
        return false;
    else {
        // printArray(path);
        if (map[path[pos - 1]][v] == 0) // không tồn tại đường đi giữa pos và v
            return false;
        else
            for (int i = 1; i < pos; i++)
                if (path[i] == v) // đỉnh v thuộc đường đi đã đi qua
                    return false;
    }
    return true;
}

void Hamiltonian(vector<vector<int>> graph, vector<int> &path, int pos) {
    // cout << "Hamiltonian " << pos << endl;
    if (pos == n + 1) {
        // cout << "result ";
        // printArray(path);
        hamiltonian_result.push_back(path);
    } else
        for (int v = 1; v <= n; v++) {
            // cout << "v = " << v << endl;
            if (promising(pos, v)) {
                // cout << "saving path: pos = " << pos << " v = " << v << endl;
                path[pos] = v;
                // cout << "current path: ";
                // printArray(path);
                Hamiltonian(graph, path, pos + 1);
            }
        }
}

void printMinPath(vector<vector<int>> hal) {
    int minPath = MAX_DISTANCES;
    vector<int> currentPath;
    for (int i = 0; i < hal.size(); i++) {
        int tempDistance = 0;
        for (int j = 1; j < hal[i].size(); j++) {
            tempDistance += map[hal[i][j]][hal[i][j + 1]];
        }
        tempDistance += map[hal[i][1]][hal[i][hal[i].size() - 1]];
        if (tempDistance < minPath) {
            minPath = tempDistance;
            currentPath = hal[i];
        }
    }
    if (minPath == MAX_DISTANCES) {
        cout << "Cannot found path!" << endl;
    } else {
        printArray(currentPath);
        cout << currentPath[1] << endl;
        cout << minPath;
    }
}

int main() {
    bool read = isReadFile(filename, n);
    if (!read) {
        return 1;
    }

    // cout << "Read n = " << n << endl;
    // cout << "Road matrix" << endl;
    // printMap(map, n);
    path = vector<int>(n + 1, -1);
    path[1] = 1;
    Hamiltonian(map, path, 2);
    printMinPath(hamiltonian_result);
}
