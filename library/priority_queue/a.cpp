// Copyright (C) 2016 by iamslash

// constructing priority queues
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

void test_1() {
  std::vector<int> v = {2, 1, 4, 6, 4, 9, 0};
  std::priority_queue<int> pq(v.begin(), v.end());
  printf("%d\n", pq.top());
}

void test_2() {
  auto mycomp = [](const int& e1, const int& e2) {
    return e1 > e2;
  };
  std::vector<int> v = {2, 1, 4, 6, 4, 9, 0};
  std::priority_queue<int, std::vector<int>, decltype(mycomp)>
      pq(mycomp, v);
  printf("%d\n", pq.top());
}

class MyComp {
 private:
  bool m_b_reverse;
 public:
  explicit MyComp(const bool& b_reverse = false) {
    m_b_reverse = b_reverse;
  }
  bool operator() (const int& lhs, const int& rhs) {
    if (m_b_reverse)
      return lhs > rhs;
    return lhs < rhs;
  }
};

void test_3() {
  std::vector<int> v = {2, 1, 4, 6, 4, 9, 0};
  std::priority_queue<int, std::vector<int>, MyComp>
      pq(MyComp(false), v);
  printf("%d\n", pq.top());
}

int main() {
  test_1();
  test_2();
  test_3();
  
  return 0;
}
