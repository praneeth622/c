#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> points(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> points[i];
  }

  std::sort(points.begin(), points.end());

  int min_distance = INT_MAX;
  std::pair<int, int> result;

  for (int i = 1; i < n; i++) {
    if (points[i] - points[i - 1] < min_distance) {
      min_distance = points[i] - points[i - 1];
      result = std::make_pair(points[i - 1], points[i]);
    }
  }

  std::cout << result.first << " " << result.second << std::endl;

  return 0;
}
