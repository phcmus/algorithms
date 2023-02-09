#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<double> readedFile(string filename) {
  ifstream inputfile(filename);
  if (inputfile.is_open()) {
    int n = 0;
    inputfile >> n;
    vector<double> res(n, 0);
    for (int i = 0; i < n; i++) {
      inputfile >> res[i];
    }
    return res;
  } else {
    cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
  }
  inputfile.close();
  return vector<double>();
}

double MaxContSubSum(vector<double> vec) {
  double maxSum = 0;
  vector<double> res(vec.size(), 0);
  double curSum = 0;
  int start = 0;
  int end = 0;
  for (int i = 0; i < vec.size(); i++) {
    curSum += vec[i];
    if (curSum > maxSum) {
      maxSum = curSum;
      end = i;
    } else if (curSum < 0) {
      curSum = 0;
      start = i + 1;
    }
  }
  for (int i = start; i <= end; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  return maxSum;
}

int main() {
  string filename = "input_1.txt";
  vector<double> input = readedFile(filename);

  cout << MaxContSubSum(input) << endl;

  return 0;
}
