#include <algorithm>
#include <iostream>
using LL = int;

const int N = 5005;
static LL dp[N][N][2] = {0};
static char s[N];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    scanf("%s", s);
    memset(dp, 0, N * N * 2 * sizeof(LL));
    for (int i = 1; i <= n; i++) {
      int w = s[i - 1] - '0';
      for (int j = 1; j <= i; j++) {
        // delete current
        // use current
        if (dp[i - 1][j - 1][w] >= j - 1) {
          dp[i][j - 1][w] = std::max(dp[i][j - 1][w], dp[i - 1][j - 1][w]);
          dp[i][j][w] = std::max(dp[i][j][w], dp[i - 1][j - 1][w] + j);
          // printf("solve dp[%d][%d][%d]=%d from dp[%d][%d][%d]=%d + %d\n", i,
          // j,
          //        w, dp[i][j][w], i - 1, j - 1, w, dp[i - 1][j - 1][w], j);
        }
        if (dp[i - 1][j - 1][1 - w] >= j - 1) {

          dp[i][j - 1][1 - w] =
              std::max(dp[i][j - 1][1 - w], dp[i - 1][j - 1][1 - w]);
          dp[i][1][w] = std::max(dp[i][1][w], dp[i - 1][j - 1][1 - w] + 1);
          // printf("solve dp[%d][1][%d]=%d from dp[%d][%d][%d]=%d + 1\n", i, w,
          //        dp[i][1][w], i - 1, j - 1, 1 - w, dp[i - 1][j - 1][1 - w]);
        }
      }
    }
    LL ans = 0;
    for (int i = 0; i <= n; i++) {
      ans = std::max({dp[n][i][0], dp[n][i][1], ans});
    }
    printf("%d\n", ans);
  }

  return 0;
}
/*
2
10
6
010101
*/