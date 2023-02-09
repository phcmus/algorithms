#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string filename = "input_2.txt";
int n = 0;
vector<vector<int>> a;

bool isReadFile(string filename) {
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

void printVector(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void output() {
  cout << nQueens.size() << endl;
  for (int i = 0; i < nQueens.size(); i++) {
    printVector(nQueens[i], nQueens[i].size());
  }
}

bool promising(int i) {
  int j = 1;
  bool flag = true;
  while (j < i && flag) {
    if (col[i] == col[j] || abs(col[i] - col[j]) == i - j)
      flag = false;
    j++;
  }
  return flag;
}

void save(int col[], int n) {
  nQueens.push_back(vector<int>(col + 1, col + n + 1));
}

void n_Queens(int i) {
  for (int j = 1; j <= n; j++) {
    col[i] = j;
    if (promising(i))
      if (i == n)
        save(col, n);
      else
        n_Queens(i + 1);
  }
}

int main() {
  bool read = isReadFile(filename, n);
  if (!read) {
    return 1;
  }

  // cout << "Read n = " << n << endl;
  col = new int[n + 1];
  n_Queens(1);
  output();
  delete col;
}
