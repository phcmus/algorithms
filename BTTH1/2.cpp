#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#define MAX_VALUE 99999

using namespace std;

vector<int> readedFile(string filename, int &total) {
  ifstream inputfile(filename);
  if (inputfile.is_open()) {
    vector<int> res;
    int temp = 0;
    while (true) {
      inputfile >> temp;
      if (inputfile.eof())
        break;
      // cout << i << " " << temp;
      res.push_back(temp);
    }
    total = temp;
    inputfile.close();
    res.pop_back();
    return res;
  } else {
    cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
  }
  inputfile.close();
  return vector<int>();
}
bool validateData(int total, vector<int> input) {
  if (total == 0 && input.size() == 0) {
    cout << "Chua nap duoc du lieu!" << endl;
    return false;
  }
  return true;
}
int getMinNumberOfCoins(vector<int> coins, int sum) {
  if (sum == 0) {
    return 0; // base case
  }
  int result = MAX_VALUE;
  for (int i = 0; i < coins.size(); i++) {
    if (coins[i] <= sum) {
      result = min(result, getMinNumberOfCoins(coins, sum - coins[i]) + 1);
    }
  }
  return result;
}
int main() {
  string filename = "input_2.txt";
  int total = 0;
  vector<int> input = readedFile(filename, total);

  if (validateData(total, input)) {
    vector<int> countCoin(input.size(), 0);
    cout << getMinNumberOfCoins(input, total);
  }

  return 0;
}
