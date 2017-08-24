# C++Tips (C++11, C++14, C++17)


## Contents

* [auto](#auto)
* [range based for](#range-based-for)
* [initializer lists](#initializer)
* [tuple](#tuple)
* [lambda](#lambda-function)
* [move semantics](#move-semantics)
* [Value Categories](#value-categories)
* [r-value reference](#r-value-reference)
* [move constructor](#move-constructor)
* [std::array](#std::array)
* [timer](#timer)
* [regex](#regex)
* [random](#random)
* [thread](#thread)
* [to_string](#to_string)
* [convert string](#convert-string)

## auto

```cpp
```

## range based for

```cpp
```

## initializer lists

```cpp
//
std::pair<std::string, std::string> get_name() {
  return {"BAZ", "baz"};
}
//
struct vector3 {
  int x, y, z;
  vector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};
//
std::map<std::string, std::string> M = { {"FOO", "foo"}, {"BAR", "bar"} };
//
for (const auto & x : {2, 3, 5, 7}) {
  std::cout << x << std::endl;
}
```

## tuple
## lambda

```cpp
  // [capture] (parameter) -> return type {body}

  std::function<int(int)> f;
  f = [&f](int x) -> int {
    if (x <= 1)
      return x;
    return f(x - 1) + f(x - 2);
  };
```

## move semantics

- Matrix클래스를 사용한 나쁜 예.

```cpp
// bad 
typedef vector<vector<int>> Matrix;
void multiply(const Matrix& A, const Matrix& B, Matrix& C);
Matrix C;
multiply(A, B, C);
print(C);
```
- Matrix클래스를 사용한 좋은 예. host부분을 주목하자. 위에서 처럼
  연산의 결과에 해당하는 Matrix를 미리 선언할 필요 없다.

```cpp
Matrix operator* (const Matrix* A, const Matrix& B) {
  size_t n = A.size();
  Matrix C(n, n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        C[i][j] += A[i][k] + B[k][j];
  return C;
}
Matrix E = (D * D) + I;
E = E * E;
```

- c++11에서 RVO(Return Value Optimization)덕분에 Matrix 값 복사는
  일어나지 않는다. rvalue가 return된다.
  
## Value Categories

~[](_img/value_category.png)

- [Value categories @ cppreference](http://en.cppreference.com/w/cpp/language/value_category)
- lvalue
  - 주소값이 있는 변수
  - `a = b`, `a += b`, `a %= b`
  - `++a`, `--a`
  - `*p`
  - `a[n]`
  - `a.m`
  - `p->m`
  - `a.*mp`
  - `p->*mp`
  - `a, b`
  - `a ? b : c`에서 b, c
  - `"Hello, world"`
  - `static_cast<int&>(x)`
- prvalue (pure rvalue)
  - `42`, `true`, `nullptr`
    - a literal except for string literal
  - `str.substr(1, 2)`, `str1 + str2`, `it++`
    - a function call or an overloaded operator expression of non-reference return type
  - `a++`, `a--`
    - the built-in post-increment and post-decrement expressions
  - `a+b`, `a%b`, `a&b`, `a<<b`
    - the built-in arithmetic expressions
  - `a && b`, `a || b`, `!a` 
    - the built-in logical expressions
  - `&a`
    - built-in address-of expression
  - `p->m`
    - built-in member of pointer expression
  - `a.*mp`
    - the pointer to member of object expression
  - `p->*mp`
    - `a, b`
    - the built-in comman expression, where b is an rvalue
  - `a ? b : c`
    - the ternary onditional expression for some b and c
  - `static_cast<double>(x)`, `std::string{}`, `(int)42`
    - a cast expression to non-reference type
  - `this`
  - `[](int x){return x * x;}`
    - a lambda expression

- xvalue (expiring value)
  - `std::move(x)`
  - `a[n]`
  - `a.m`
  - `a.*mp`
  - `a ? b : c` 의 b, c
  - `static_cast<char&&>(x)`
- glvalue (generalized value)
  - lvalue, xvalue
- rvalue 
  - xvalue, prvalue
  
## r-value reference

- foo는 rvalue argument를 받아 낼 수 있다.

```cpp
vector<int> foo(vector<int>&& a, vector<int>&& b) { }
vector<int> bar(int n) {}
int main() {
  vector<int> c = foo(vector<int> {0}, bar(5)};
  for (int e : c)
    cout << x << ' ';
  cout << endl;
  return 0;
}
```

## move constructor

- 값 복사 없이 메모리가 이동하는 형태를 move semantic이라고 한다. move
  semantic이 가능한 생성자를 move constructor라고 한다.

```cpp
template<typename T>
struct vector {
  vector();
  vector(size_t size); // constructor
  vector(vector<T> &a); // copy constructor
  vector(vector<T> &&a); // move constructor
};
```

## std::array

```cpp
array<int, 6> a = {1, 2, 3};
```

- vector와 다르게 크기가 고정된 배열이다.
- int[]와 다른점은 무엇일까?
  - STL algorithm함수 들에 적용이 가능하다. (ex. begin, end)
  - 값 복사, 사전순 비교 등이 쉽다. 
  - assertive하게 동작 (out-of-index일때 바로 throw)
  
## timer

```cpp
using namespace std::chrono;
auto _start = system_clock::now();
auto _end = system_clock::now();
long millisecs = duration_cast<milliseconds>(_end - _start).count();
```

## regex

```cpp
if (regex_match("ABCD", regex("(A|B)C(.*)D"))) { 
  //... 
}
```

- [a.cpp](library/regex/a.cpp)

## random

```cpp
std::mt19936 eng; // Mersenne Twister
std::uniform_int_distribution<int> U(-100, 100);
for (int i = 0; i < n; ++i)
  cout << U(eng) << std;
```

## thread

```cpp
```

## to_string

```cpp
string s = std::to_string(10);
string s = std::to_string(3.1415926535);
```

## convert string

- stod, stof, stoi, stol, stold, stoll, stoul, stoull

```cpp
int x = stoi("-1");
long long y = stoll("2147483648");
long long z = stoll("1000...0000", 0, 2); // 4294967296
```


# REFERENCE

- [c++ language](http://en.cppreference.com/w/cpp/language)
- [cplusplus.com](https://www.cplusplus.com)
- [c++11FAQ](http://pl.pusan.ac.kr/~woogyun/cpp11/C++11FAQ_ko.html)
