#include "Point.cpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

class PointAngle {
public:
  Point p;
  double angle;

  PointAngle(Point pp, double aangle) {
    p = pp;
    angle = aangle;
  }
};

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

double computeAngle(Point from, Point to) {
  double angle = atan2(to.y - from.y, to.x - from.x);
  if (angle < 0)
    angle += M_PI;
  return angle;
}

PointAngle findNextExtremePoint(vector<Point> &S, Point cur, double curAngle) {
  // cout << "S size 1 = " << S.size() << endl;
  double minAngle = 2 * M_PI;

  for (int i = 0; i < S.size(); i++) {
    if (S[i].x == cur.x && S[i].y == cur.y) {
      S.erase(S.begin() + i);
      break;
    }
  }

  // cout << "S size 2 = " << S.size() << endl;

  Point next;

  for (int i = 0; i < S.size(); i++) {
    double angle = computeAngle(cur, S[i]);
    if (angle < minAngle && angle >= curAngle) {
      next = S[i];
      minAngle = angle;
    }
  }
  // S.push_back(cur);
  return PointAngle(next, minAngle);
}

vector<Point> computeConvexHull(vector<Point> S) {
  vector<Point> convexHull;

  Point first = S[0];
  double miny = first.y;

  for (int i = 1; i < S.size(); i++) {
    if (S[i].y < miny) {
      first = S[i];
      miny = first.y;
    }
  }

  convexHull.push_back(first);

  double curAngle = 0;
  Point cur = first;

  while (true) {
    PointAngle pA = findNextExtremePoint(S, cur, curAngle);

    curAngle = pA.angle;
    if (first.x == pA.p.x && first.y == pA.p.y)
      break;
    convexHull.push_back(pA.p);
    cur = pA.p;
  }

  return convexHull;
}

int main() {
  string filename = "input_4.txt";
  vector<Point> input = readedFile(filename);

  if (validateData(input)) {
    vector<Point> result(computeConvexHull(input));
    for (int i = 0; i < result.size(); i++) {
      cout << "(" << result[i].x << "," << result[i].y << ") ";
    }
    cout << endl;
  }

  return 0;
}
