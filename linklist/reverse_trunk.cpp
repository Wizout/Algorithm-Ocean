// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478634682663895040
// 21:55 - 22:18


#include <iostream>
#include <unordered_map>
#include <stack>

int reverse_trunk() {
  int fst_addr = 0;
  int count = 0, block_size = 0;

  std::cin >> fst_addr >> count >> block_size;

  struct Store {
    Store(int d, int n): data{ d }, next{ n } {}

    int data;
    int next;
  };

  std::unordered_map<int, Store> umap;
  int addr = 0, data = 0, next = 0;

  for (int i = 0; i < count; ++i) {
    std::cin >> addr >> data >> next;

    umap[addr] = Store(data, next);
  }

  std::stack<int> s;
  int last_hdr = -1, remainder = 0, current_addr = fst_addr;
  int current_hdr = 0, next_addr = 0, last_addr = 0;
  for (int i = 0; i < count; ++i) {
    next_addr = umap[current_addr].next;

    if (-1 == next_addr)
      last_addr = current_addr;

    remainder = i % block_size;
    if (block_size - 1 == remainder) {
      umap[current_addr].next = last_hdr;
      last_hdr = current_hdr;
    }
    if (0 == remainder) {
      s.push(current_addr);
      current_hdr = current_addr;
    }

    current_addr = next_addr;
  }

  return 0;
}
