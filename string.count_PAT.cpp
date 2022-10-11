// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805282389999616
// Time(s): FAIL
// Cost: 43 min +

#include <iostream>
#include <string>
#include <list>

int count_pat() {
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
