// Copyright (C) 2016 by iamslash

/* map example */
#include <cstdio>      /* printf */
#include <map>     /* assert */
#include <algorithm>

bool fncomp (char lhs, char rhs) { return lhs < rhs; }
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const {
    return lhs < rhs;
  }
};

int main() {
  // map::map
  std::map<char, int> first;
  first['a'] = 10;
  first['b'] = 30;
  first['c'] = 50;
  first['d'] = 70;
  std::map<char, int> second(first.begin(), first.end());
  std::map<char, int> third(second);
  std::map<char, int, classcomp> fourth;
  bool(*fn_pt)(char, char) = fncomp;
  std::map<char, int, bool(*)(char, char)> fifth(fn_pt);
  std::map<char, int, bool(*)(char, char)> sixth(fncomp);

  // map::emplace, map::emplace_hint
  first.emplace('e', 90);
  first.emplace_hint(first.end(), 'f', 110);

  // map::begin, map::end, map::rbegin, map::rend
  // for (auto it = first.begin(); it != first.end(); ++it) {
  //   printf("%c : %d\n", (*it).first, (*it).second);
  // }
  // for (auto it = first.rbegin(); it != first.rend(); ++it) {
  //   printf("%c : %d\n", (*it).first, (*it).second);
  // }

  // map::equal_range
  auto r = first.equal_range('b');
  printf("lower bound points to: %c => %d\n", r.first->first, r.first->second);
  printf("upper bound points to: %c => %d\n", r.second->first, r.second->second);

  // max value element
  auto it = std::max_element(first.begin(), first.end(),
                            [](const std::pair<char, int>& lhs,
                               const std::pair<char, int>& rhs) {
                              return lhs.second < rhs.second;
                            });
  printf("%c : %d is the max value element\n", it->first, it->second);

  return 0;
}
