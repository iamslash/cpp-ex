
# lambda function

```cpp
  // [capture] (parameter) -> return type {body}

  std::function<int(int)> f;
  f = [&f](int x) -> int {
    if (x <= 1)
      return x;
    return f(x - 1) + f(x - 2);
  };
```

# REFERENCE

- [c++11FAQ](http://pl.pusan.ac.kr/~woogyun/cpp11/C++11FAQ_ko.html)
- [cplusplus.com](https://www.cplusplus.com)
- [cppreference.com](http://www.cppreference.com)
