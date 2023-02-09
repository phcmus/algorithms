class Point {
public:
  double x, y;

  Point() { this->x = this->y = 0; }
  Point(int xx, int yy) {
    this->x = xx;
    this->y = yy;
  }
  bool operator==(const Point &other) {
    return this->x == other.x && this->y == other.y;
  }
};
