// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805321640296448
// Time(s): 4. WA, CE, WA, AC
// Cost: 17:15 - 17:42. 27 min


#include <iostream>
#include <cstring>

// Case   Score    Time    Memory
//  0      12       4ms     452KB
//  1       2       3ms     320KB
//  2       6       4ms     440KB
int max_min() {
  char max_name[16]{}, min_name[16]{}, max_cls[16]{}, min_cls[16]{};
  int times = 0, min = 233, max = 233;

  auto update_record {
    [&](char* dst_name, char* dst_cls, char* src_name, char* src_cls) -> void {
      strncpy(dst_name, src_name, 16);
      dst_name[strnlen(src_name, 16)] = '\0';

      strncpy(dst_cls, src_cls, 16);
      dst_cls[strnlen(src_cls, 16)] = '\0';
    }
  };

  scanf("%d", &times);
  while (times-- > 0) {
    char name[16]{}, cls[16]{};
    int score = 0;

    scanf("%s %s %d", name, cls, &score);
    if (233 == min || score < min) {
      min = score;
      update_record(min_name, min_cls, name, cls);
    }

    if (233 == max || score > max) {
      max = score;
      update_record(max_name, max_cls, name, cls);
    }
  }

  std::cout << max_name << ' ' << max_cls << std::endl;
  std::cout << min_name << ' ' << min_cls << std::endl;

  return 0;
}
