#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string filename = "input_6.txt";
int total = 0;
vector<int> a;

bool isReadFile(string filename) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        int temp = -1;

        inputfile >> temp;

        while (temp != 1) {
            a.push_back(temp);
            inputfile >> temp;
        }

        a.push_back(temp);
        inputfile >> total;

        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int coinChange(vector<int> coins, int n, int sum) {
    if (sum == 0)
        return 1;

    if (sum < 0)
        return 0;

    if (n <= 0)
        return 0;

    return coinChange(coins, n - 1, sum) +
           coinChange(coins, n, sum - coins[n - 1]);
}

// int moneyChange(vector<int> coins, int money) {
//     for (int i = 0; i < coins.size(); i++)
//         if (coins[i] == money)
//             return 1;
//     int minCoins = money;
//     for (int i = 0; i < coins.size(); i++)
//         if (money > coins[i]) {
//             int tmpSum = 1 + moneyChange(coins, money - coins[i]);
//             if (tmpSum < minCoins)
//                 minCoins = tmpSum;
//         }
//     cout << "return " << minCoins << endl;
//     return minCoins;
// }

int minCoins = 999999;
int moneyChange(vector<int> coins, int money) {
    for (int i = 0; i < coins.size(); i++) {
        cout << "money " << money << endl;
        if (coins[i] == money)
            return 1;
    }
    cout << "break " << money << endl;
    minCoins = money;
    for (int i = 0; i < money / 2; i++) {
        int tmpSum = moneyChange(coins, i) + moneyChange(coins, money - i);
        if (tmpSum < minCoins)
            minCoins = tmpSum;
    }

    return minCoins;
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }

    printVector(a);
    cout << moneyChange(a, total);

    return 0;
}
