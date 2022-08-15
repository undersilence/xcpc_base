#include <algorithm>
#include <iostream>
#include <vector>


int main() {
  int n;
  std::vector<int> a;
  while (~scanf("%d", &n)) {
    for (int i = 0, x; i < n; i++) {
      scanf("%d", &x);
      a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < a.size(); i++) {
      printf("%d\n", a[i]);
    }
  }

  return 0;
}