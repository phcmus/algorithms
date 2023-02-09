#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> arr = vector<int>{1, 2, 3, 4};
vector<vector<int>> res;
int count = 0;

void printArr(vector<int> arr) {
  for (int ele : arr) {
    cout << ele << " ";
  }
  cout << endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// ---------------------------------------

void suffle(int pivotId, vector<int> &arr) {
  if (pivotId == arr.size() - 1) {
    printArr(arr);
    count++;
  } else {
    for (int i = 0; i < arr.size(); i++) {
      swap(arr[i], arr[pivotId]);
      suffle(pivotId + 1, arr);
      swap(arr[i], arr[pivotId]);
    }
  }
}

// ---------------------------------------

vector<int> values = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<vector<int>> sudoku_board = {
    {0, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 1, 0, 0, 0},
    {0, 7, 8, 0, 0, 0, 0, 0, 1}, {0, 0, 4, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 2, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

void printBoard(vector<vector<int>> board) {
  for (vector<int> row : board) {
    for (int cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// bool promising() {}

void sudoku(vector<int> board) {}

// ---------------------------------------

int main() {
  // printBoard(sudoku_board);
  suffle(0, arr);
  cout << count << endl;
  return 0;
}
