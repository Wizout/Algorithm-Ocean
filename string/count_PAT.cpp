// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805282389999616
// Time(s): FAIL + FAIL + AC
// Cost: 43 min + 41 min + 91 min

#include <iostream>
#include <string>
#include <list>
#include <vector>

// 14:22 - 15:53
// Case  Result  Score   Run Time   Memory
// 0 Accepted 14 4 ms 476 KB
// 1 Accepted 1 4 ms 324 KB
// 2 Accepted 2 11 ms 1584 KB
// 3 Accepted 4 10 ms 1852 KB
// 4 Accepted 4 7 ms 1776 KB
int third() {
  std::string input;
  std::cin >> input;

  std::vector<std::string::size_type> p, a, t;

  for (std::string::size_type i = 0; i < input.length(); ++i) {
    switch (input[i]) {
    case 'P':
      p.push_back(i);
      break;
    case 'A':
      a.push_back(i);
      break;
    case 'T':
      t.push_back(i);
      break;
    default:
      break;
    }
  }

  if (p.empty() || a.empty() || t.empty()) {
    std::cout << 0 << std::endl;
    return 0;
  }

  uint64_t times = 0;

  auto it_p = p.begin(), it_a = a.begin();
  std::string::size_type cache_p = 0, cache_t = 0;

  // Calculate P{< hi}
  auto less_than_p {
    [&](std::string::size_type hi) -> std::string::size_type {
      while (it_p != p.end() && *it_p < hi) {
        ++cache_p;
        ++it_p;
      }
      return cache_p;
    }
  };

  for (auto it_t = t.begin(); it_t != t.end(); ++it_t) {
    while (it_a != a.end() && *it_a < *it_t) {
      cache_t = cache_t + less_than_p(*it_a);
      ++it_a;
    }
    times = times + cache_t;
  }

  std::cout << times % 1000000007 << std::endl;

  return 0;
}

// 22:22 - 23:03
// Case  Result  Score  Run Time  Memory
// 0  Accepted  14  3 ms  492 KB
// 1  Accepted  1  3 ms  328 KB
// 2  Time Limit Exceeded  0  --  1588 KB
// 3  Time Limit Exceeded  0  --  1692 KB
// 4  Time Limit Exceeded  0  --  1908 KB
int second() {
  std::string input;
  std::cin >> input;

  std::vector<std::string::size_type> p, a, t;

  for (std::string::size_type i = 0; i < input.length(); ++i) {
    switch (input[i]) {
    case 'P':
      p.push_back(i);
      break;
    case 'A':
      a.push_back(i);
      break;
    case 'T':
      t.push_back(i);
      break;
    default:
      break;
    }
  }

  uint64_t times = 0;
  for (auto pit = p.begin(); pit != p.end(); ++pit) {
    for (auto ait = a.begin(); ait != a.end(); ++ait) {
      if (*pit > *ait)
        continue;

      for (auto tit = t.begin(); tit != t.end(); ++tit) {
        if (*ait > *tit)
          continue;
        ++times;
      }
    }
  }

  std::cout << times % 1000000007 << std::endl;

  return 0;
}

// Case  Result  Score  Run Time  Memory
// 0 Wrong Answer 0 4 ms 440 KB
// 1 Accepted 1 5 ms 616 KB
// 2 Time Limit Exceeded 0 -- 812 KB
// 3 Wrong Answer 0 10 ms 732 KB
// 4 Time Limit Exceeded 0 -- 1588 KB
int first() {
  const char* pattern = "PAT";

  std::string input;
  std::cin >> input;

  std::list<char*> lst;
  uint64_t match = 0;

  auto update_ptr {
    [&](const char current) -> void {
      auto it = lst.begin();
      while (it != lst.end()) {
        if (*(*it) == current)
          ++(*it);

        if (*(*it) == '\0') {
          ++match;

          auto backup = ++it;
          lst.erase(--it);
          it = backup;

          continue;
        }

        ++it;
      }
    }
  };

  for (std::string::size_type i = 0; i < input.size(); ++i) {
    if (pattern[0] == input[i]) {
      char* p = const_cast<char*>(&pattern[1]);
      lst.push_back(p);
      continue;
    }

    update_ptr(input[i]);
  }

  std::cout << match % 1000000007 << std::endl;

  return 0;
}
