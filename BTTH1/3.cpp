#include "Point.cpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Point> readedFile(string filename) {
  ifstream inputfile(filename);
  if (inputfile.is_open()) {
    vector<Point> res;
    inputfile.ignore(1, '\n');
    while (true) {
      Point tempPoint = Point();
      inputfile >> tempPoint.x >> tempPoint.y;
      if (inputfile.eof())
        break;
      res.push_back(tempPoint);
    }
    return res;
  } else {
    cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
  }
  inputfile.close();
  return vector<Point>();
}

bool validateData(vector<Point> points) {
  if (points.size() == 0) {
    cout << "Danh sach diem trong!" << endl;
    return false;
  }

  return true;
}

vector<vector<Point>> BruteForceClosestPoints(vector<Point> points) {
  long int dmin = 9999999999;
  int n = points.size();
  Point point1, point2;
  vector<vector<Point>> result;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = sqrt(pow(points[i].x - points[j].x, 2) +
                   pow(points[i].y - points[j].y, 2));
      if (d < dmin) {
        dmin = d;
        point1 = points[i];
        point2 = points[j];
        result.push_back(vector<Point>({point1, point2}));
      } else if (d == dmin) {
        point1 = points[i];
        point2 = points[j];
        result.push_back(vector<Point>({point1, point2}));
      }
    }
  }

  return result;
}

int main() {
  string filename = "input_3.txt";
  int total = 0;
  vector<Point> input = readedFile(filename);

  if (validateData(input)) {
    vector<vector<Point>> result(BruteForceClosestPoints(input));
    for (int i = 0; i < result.size(); i++) {
      cout << "(" << result[i][0].x << "," << result[i][0].y << ") ("
           << result[i][1].x << "," << result[i][1].y << ")" << endl;
    }
  }

  return 0;
}
