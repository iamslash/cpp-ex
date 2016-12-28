// Copyright (C) 2016 by iamslash

#include <iostream>
#include <set>

int main() {

  // equal_range
  std::set<int> myset;
  for (int i = 1; i <= 5; ++i) {
    myset.insert(i * 10);
  }
  std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> r;
  r = myset.equal_range(30);
  std::cout << "the lower bound points to: " << *r.first << std::endl;
  std::cout << "the upper bound points to: " << *r.second << std::endl;

  // insert duplicated element
  myset.insert(30);
  myset.insert(30);
  myset.insert(30);
  for (const int& x : myset) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  return 0;
}
