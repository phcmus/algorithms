#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

string filename = "input_8.txt";
vector<vector<int>> cities_distances = vector<vector<int>>();
int n = 0;

bool isReadFile(string filename) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        inputfile >> n;
        cities_distances = vector<vector<int>>(n, vector<int>(n, 0));

        while (!inputfile.eof()) {
            int i, j, distance;
            inputfile >> i >> j >> distance;
            if (i == -1) {
                break;
            }
            cities_distances[i - 1][j - 1] = distance;
            cities_distances[j - 1][i - 1] = distance;
        }

        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printMatrix(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> TSP(vector<vector<int>> cities_distances) {
    int n = cities_distances.size();
    vector<vector<int>> dp = vector<vector<int>>(1 << n, vector<int>(n, 0));
    vector<vector<int>> parent = vector<vector<int>>(1 << n, vector<int>(n, 0));

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = 1e9;
        }
    }

    dp[1][0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == 1e9) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    continue;
                }

                if (dp[mask | (1 << j)][j] >
                    dp[mask][i] + cities_distances[i][j]) {
                    dp[mask | (1 << j)][j] =
                        dp[mask][i] + cities_distances[i][j];
                    parent[mask | (1 << j)][j] = i;
                }
            }
        }
    }

    vector<int> path;
    int cur = 0;
    int mask = (1 << n) - 1;

    while (path.size() < n) {
        path.push_back(cur);
        int next = parent[mask][cur];
        mask ^= (1 << cur);
        cur = next;
    }
    printMatrix(parent);

    return path;
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }

    printMatrix(cities_distances);

    vector<int> result = TSP(cities_distances);
    printVector(result);

    return 0;
}
