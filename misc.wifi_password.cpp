// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805262622244864
// Time(s): 1 time
// Cost: 22 min

#include <iostream>
#include <vector>
#include <cstdint>

int wifi_password() {
  int times = 0;
  scanf("%d", &times);
  getchar();  // '\n'

  std::vector<uint8_t> result(times);

  for (int i = 0; i < times; ++i) {
    char opt = '\0', tf = '\0';

    for (int each = 0; each < 4; ++each) {
      scanf("%c", &opt);
      getchar();  // '-'
      scanf("%c", &tf);
      getchar();  // '\n'

      if (tf == 'T') {
        result[i] = opt - 'A' + 1;

        while (++each < 4) {
          scanf("%c-%c", &opt, &tf);
          getchar();
        }

        break;
      }
    }
  }

  for (auto i: result)
    std::cout << (int)i;

  putchar('\n');

  return 0;
}
