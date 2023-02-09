#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string filename = "input_5.txt";
int n = 0;
vector<int> coins = vector<int>(0, 0);

bool isReadFile(string filename) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {

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

int changeCoinsDP(vector<int> coins, int k, int money) {
    vector<int> C = vector<int>(coins.size(), 0);
    for (int cents = 1; cents <= money; cents++) {
        int minCoins = cents;
        for (int i = 1; i <= k; i++) {
            if (coins[i] > cents)
                continue;
            if (C[cents - coins[i]] + 1 < minCoins)
                minCoins = C[cents - coins[i]] + 1;
        }
        C[cents] = minCoins;
    }
    return C[money];
}

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }

    // printVector(coins);
    // cout << money << endl;

    int result = changeCoinsDP(coins, coins.size(), money);
    cout << result << endl;

    return 0;
}
