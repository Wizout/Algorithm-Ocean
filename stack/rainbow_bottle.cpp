// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858889
// Time(s): 1 time
// Cost: about 45 min

#include <iostream>
#include <stack>

int srb() {
  int balls = 0, shelves = 0, times = 0;

  scanf("%d %d %d", &balls, &shelves, &times);

  while (times--) {
    std::stack<int> s;
    int expected = 1, current = 0;

    for (int i = 0; i < balls; ++i) {
      scanf("%d", &current);
      getchar();

      if (current == expected) {
        ++expected;
        current = 0;  // reset
      }

      while (!s.empty() && expected == s.top()) {
        ++expected;
        s.pop();
      }

      if (0 != current) {
        if (s.size() + 1 > shelves || (!s.empty() && s.top() < current)) {
          while (++i < balls) {
            scanf("%d", &current);
            getchar();
          }

          break;
        }
        s.push(current);
      }
    }

    while (!s.empty() && expected == s.top()) {
      ++expected;
      s.pop();
    }

    if (expected > balls)
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
