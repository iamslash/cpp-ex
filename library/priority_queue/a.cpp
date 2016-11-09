// Copyright (C) 2016 by iamslash

// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison {
  bool reverse;
 public:
  explicit mycomparison(const bool& revparam = false) {
    reverse = revparam;
  }
  bool operator() (const int& lhs, const int&rhs) const {
    if (reverse)
      return (lhs > rhs);
    else
      return (lhs < rhs);
  }
};

int main() {
  // ::constructor
  int myints[] = {10, 60, 50, 20};

  // std::priority_queue<int> first;
  // std::priority_queue<int> second(myints, myints + 4);
  // std::priority_queue<int, std::vector<int>,
  //                     std::greater<int> > third(myints, myints + 4);
  // // using mycomparison:
  // typedef std::priority_queue<int, std::vector<int>, mycomparison> mypq_type;

  // mypq_type fourth;                       // less-than comparison
  // mypq_type fifth(mycomparison(true));   // greater-than comparison

  //
  // std::priority_queue<int, std::vector<int>, std::less<int> >
  //     max_heap(myints, myints + 4);
  // std::priority_queue<int, std::vector<int>, std::greater<int> >
  //     min_heap(myints, myints + 4);
  // printf("%d %d\n", max_heap.top(), min_heap.top());

  std::priority_queue<int, std::vector<int>, std::less<int> > q;
  printf("%d\n", q.top());

  return 0;
}
