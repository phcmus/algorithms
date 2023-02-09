#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string filename = "input_2.txt";
int n = 0;

vector<int> col{1, 2, 2, 1, -1, -2, -2, -1};
vector<int> row{2, 1, -1, -2, -2, -1, 1, 2};
vector<vector<int>> h;

bool isReadFile(string filename, int &n) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        inputfile >> n;
        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void printMap(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void KnightTour(int i, int r, int c) {
    // cout << "i = " << i << " r = " << r << " c = " << c << endl;
    for (int k = 0; k < 8; k++) { // 8 positions a time
        // cout << "k = " << k << endl;
        int u = r + row[k];
        int v = c + col[k];
        // cout << "some thing " << u << v << endl;
        // printMap(h);

        // cout << "last time u v " << u << " " << v << " " << n << endl;
        // cout << "oh no " << h.size() << " " << h[10].size() << endl;

        if (0 <= u && u < n && 0 <= v && v < n && h[u][v] == -1) {
            // cout << "vao if";
            h[u][v] = i;
            if (i == n * n - 1) {
                printMap(h);
                return;
            } else
                KnightTour(i + 1, u, v);
            // cout << "final break " << u << v << endl;
            h[u][v] = -1;
        }
        // cout << "oh no" << endl;
    }
    // cout << "should go here 1" << endl;
}

int main() {
    bool read = isReadFile(filename, n);
    if (!read) {
        return 1;
    }

    // cout << "Read n = " << n << endl;
    h = vector<vector<int>>(n, vector<int>(n, -1));

    h[0][0] = 0;

    KnightTour(1, 0, 0);
}
