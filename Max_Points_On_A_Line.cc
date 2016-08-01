#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <stdlib.h>

using namespace std;

struct Point {
  int x;
  int y;
  Point():x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  public:
    int maxPoints(vector<Point> &points);
};

int Solution::maxPoints(vector<Point> &points) {
  int max = 0;
  int same = 0;
  int count = 0;
  const int size = points.size();
  if (size == 0) return 0;
  for (int i=0; i < size; ++i) {
    same = 1;
    for (int j=i+1; j < size; ++j) {
      int x1 = points[i].x;
      int y1 = points[i].y;
      int x2 = points[j].x;
      int y2 = points[j].y;
      count = 0;
      if (x1 == x2 && y1 == y2) {
        ++same;
        continue;
      } else if (x1 == x2) {
        for (int k=0; k < size; ++k) {
          if (points[k].x == x1)
            ++count;
        }
        max = count > max ? count : max;
        continue;
      }

      double a = double(y2-y1) / double(x2-x1);
      for (int k=0; k < size; ++k) {
        if (points[k].x == x1 && points[k].y == y1)
          ++count;
        else if (double(points[k].y - y1) / 
            double(points[k].x - x1) == a)
          ++count;
      }
      max = count > max ? count : max;
    }
    max = same > max ? same : max;
  }
  return max;
}

int main(int argc, char **argv) {
  Solution s;
  vector<Point> vp;
  vp.push_back(Point(3, 1));
  vp.push_back(Point(12, 3));
  vp.push_back(Point(3, 1));
  vp.push_back(Point(-6, -1));

  cout << s.maxPoints(vp) << endl;
}
