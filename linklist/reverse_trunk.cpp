// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478634682663895040
// 21:55 - 22:18


#include <iostream>
#include <unordered_map>

int reverse_trunk() {
  int fst_addr = 0;
  int count = 0, block_size = 0;

  std::cin >> fst_addr >> count >> block_size;

  std::unordered_map<int, std::pair<int, int>> umap;
  int addr = 0, data = 0, next = 0;
  int actual_count = 0;

  for (int i = 0; i < count; ++i) {
    std::cin >> addr >> data >> next;

    umap[addr] = std::pair<int, int>(data, next);
    if (next != -1)
      ++actual_count;
  }
  ++actual_count;

  int last_hdr = -1, remainder = 0, current_addr = fst_addr;
  int current_hdr = current_addr, next_addr = 0, last_addr = fst_addr;
  if (1 == block_size) {
    for (int i = 0; i < actual_count; ++i) {
      next_addr = umap[current_addr].second;
      umap[current_addr].second = last_hdr;
      last_hdr = current_addr;
      current_addr = next_addr;
    }
    last_addr = last_hdr;
  }
  else if (block_size != actual_count) {
    for (int i = 0; i < actual_count; ++i) {
      next_addr = umap[current_addr].second;

      remainder = i % block_size;
      if (block_size - 1 == remainder || i + 1 == actual_count) {
        umap[current_addr].second = last_hdr;
        last_hdr = current_hdr;
      }
      if (0 == remainder) {
        last_addr = current_addr;
        current_hdr = current_addr;
      }

      current_addr = next_addr;
    }
  }

  next_addr = last_addr;
  while (true) {
    if (-1 == umap[next_addr].second)
      break;

    printf("%05d %d %05d\n", next_addr, umap[next_addr].first, umap[next_addr].second);
    next_addr = umap[next_addr].second;
  }

  printf("%05d %d %d\n", next_addr, umap[next_addr].first, umap[next_addr].second);

  return 0;
}

/*
Case  Result  Score  Run Time  Memory
0  Accepted  12  3 ms  476 KB
1  Accepted  3  3 ms  484 KB
2  Accepted  2  3 ms  316 KB
3  Accepted  2  3 ms  324 KB
4  Accepted  2  3 ms  324 KB
5  Accepted  3  98 ms  6092 KB
6  Wrong Answer  0  4 ms  440 KB
*/
int first() {
  int fst_addr = 0;
  int count = 0, block_size = 0;

  std::cin >> fst_addr >> count >> block_size;

  std::unordered_map<int, std::pair<int, int>> umap;
  int addr = 0, data = 0, next = 0;

  for (int i = 0; i < count; ++i) {
    std::cin >> addr >> data >> next;

    umap[addr] = std::pair<int, int>(data, next);
  }

  int last_hdr = -1, remainder = 0, current_addr = fst_addr;
  int current_hdr = current_addr, next_addr = 0, last_addr = fst_addr;
  if (1 == block_size) {
    for (int i = 0; i < count; ++i) {
      next_addr = umap[current_addr].second;
      umap[current_addr].second = last_hdr;
      last_hdr = current_addr;
      current_addr = next_addr;
    }
    last_addr = last_hdr;
  }
  else if (block_size != count) {
    for (int i = 0; i < count; ++i) {
      next_addr = umap[current_addr].second;

      remainder = i % block_size;
      if (block_size - 1 == remainder || i + 1 == count) {
        umap[current_addr].second = last_hdr;
        last_hdr = current_hdr;
      }
      if (0 == remainder) {
        last_addr = current_addr;
        current_hdr = current_addr;
      }

      current_addr = next_addr;
    }
  }

  next_addr = last_addr;
  while (true) {
    if (-1 == umap[next_addr].second)
      break;

    printf("%05d %d %05d\n", next_addr, umap[next_addr].first, umap[next_addr].second);
    next_addr = umap[next_addr].second;
  }

  printf("%05d %d %d\n", next_addr, umap[next_addr].first, umap[next_addr].second);

  return 0;
}
