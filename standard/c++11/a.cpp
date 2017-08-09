// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <functional>
#include <string>
#include <chrono>
#include <regex>
#include <random>

// auto
// range-based for
// initializer lists
// std::tuple
// advanced STL container 
// lambda function
// move, r-value reference
// etc

// in-class member initializers
class Foo {
  int sum = 0;
};

// initializer lists
std::pair<std::string, std::string> get_name() {
  return {"BAZ", "baz"};
}
// initializer lists
struct vector3 {
  int x, y, z;
  vector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

// move constructor
template<typename T>
struct vector4 {
  vector4();
  vector4(size_t size);
  vector4(vector4<T> &a);  // copy constructor
  vector4(vector4<T> &&a); // move constructor
};

int main() {
  // initializer lists
  // auto
  std::map<std::string, std::string> M = { {"FOO", "foo"}, {"BAR", "bar"} };
  for (auto it = M.begin(); it != M.end(); ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
  }

  // ranged-based for
  for (auto& kv : M) {
    std::cout << kv.first << " : " << kv.second << std::endl;
  }

  //
  std::pair<std::string, std::string> r = get_name();
  std::cout << r.first << " : " << r.second << std::endl;

  //
  vector3 o = vector3(0, 0, 0);
  vector3 v = {1, 2, 3};

  // std::min, std::max는
  // std::initializer_list<T> 타입을 받을 수 있도록 오버로드 되어 있다.
  auto min_var = std::min({1, 2, 3, 4, 5}); 
  auto min_2 = std::max({0, 1, 2});

  // ranged-based for with initializer lists
  for (const auto & x : {2, 3, 5, 7}) {
    std::cout << x << std::endl;
  }

  // tuple
  std::tuple<int, int, int> t_1(1, 2, 3);
  auto t_2 = std::make_tuple(1, 2, 3);
  std::cout << std::get<0>(t_1) << " " <<
      std::get<1>(t_1) << " " <<
      std::get<2>(t_1) << " " << std::endl;

  // tuple, tie
  int a = 3, b = 4;
  std::tie(b, a) = std::make_tuple(1, 2);
  std::cout << a << " " << b << std::endl;

  // tuple list sort
  std::vector<std::tuple<int, int, int> > tv;
  tv.push_back(std::make_tuple(1, 2, 3));
  tv.push_back(std::make_tuple(2, 1, 3));
  tv.push_back(std::make_tuple(1, 1, 3));  
  std::sort(tv.begin(), tv.end());
  for (const auto& x : tv) {
    std::cout << std::get<0>(x) << " " << std::get<1>(x) << " " << std::get<2>(x) << std::endl;
  }

  // // tuple example : lexicographical comparison
  // std::sort(a.begin(), a.end(), [&](const Elem& x, const Elem& y) {
  //     return std::make_tuple(x.score, -x.age, x.submission)
  //         < std::make_tuple(y.score, -y.age, y.submission);
  //   });

  // advanced STL container
  // argument가 container의 element의 type의 생성자에 전달된다.
  std::vector<std::pair<int, int> > vvv;
  vvv.push_back(std::make_pair(3, 4));
  vvv.emplace_back(3, 4);
  std::queue<std::tuple<int, int, int> > q;
  q.emplace(1, 2, 3);

  // advanced STL container
  // unordered_set, unordered_map
  // red black tree vs hash
  std::unordered_map<long long, int> pows;
  for (int i = 0; i < 63; ++i)
    pows[1LL << i] = i;

  // lambda function
  // [captures](parameters){body}
  auto func = [](){};
  func();

  // lambda function recursive
  std::function<int(int)> f;
  f = [&f](int x) -> int {
    if (x <= 1)
      return x;
    return f(x - 1) + f(x - 2);
  };

  // lambda stl algorithms
  std::vector<int> primes = {2, 3, 5, 7, 11};
  auto is_even = [](int n){return (n & 1) == 0;};
  bool all_even = std::all_of(primes.begin(), primes.end(), is_even);

  // // r-value reference
  // std::vector<int> concat(std::vector<int> &&a, std::vector<int> &&b) {
  // }

  // r-value, move semantics
  // 빨라진다.
  std::string h = "hello";
  std::string w = "world";
  h = h + " " + w + " ? " + h + " ICPC" + w;

  // std::array
  // int[]와의 차이점은???
  // stl algorithm함수들에 적용이 가능하다.
  // 값 복사, 사전순 비교 등이 쉽다.
  // assertive하게 동작 (out-of-index일 때 바로 throw)
  {
    std::array<int, 6> a = {1, 2, 3};
  }

  // standardized timer library
  {
    auto _start = std::chrono::system_clock::now();
  }

  // regex
  {
    if (std::regex_match("ABCD", std::regex("(A|B)C(.*)D"))) {
    }
  }

  // random library
  {
    std::mt19937 eng;
    std::uniform_int_distribution<int> U(-100, 100);
    for (int i = 0; i < 10; ++i)
      std::cout << U(eng) << std::endl;
  }

  // std::to_string
  {
    std::string s = std::to_string(10);
  }

  // std::stoi, std::stol, std::stoll
  {
    int x = std::stoi(".1");
    long long y = std::stoll("2147483648");
    long long z = std::stoll("1000...0000", 0, 2);
  }

  // nullptr
  {
    nullptr;
  }

  // 128-bit integer
  {
    __int128_t a;
  }

  return 0;
}

