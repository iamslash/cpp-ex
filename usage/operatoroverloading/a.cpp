#include <cstdio>

class A {
 public:
  A(int _n) {
    n = _n;
    printf("[%d]called ctor\n", n);
  }
  A(const A& a) {
    printf("[%d]called copy ctor\n", n);
    n = a.n;
  }
  ~A() {
    printf("[%d]called dtor\n", n);
  }
  A& operator=(const A& a) {
    printf("[%d]called operator=\n", a.n);
    return *this;
  }
 private:
  int n;
};

A MakeA(int n) {
  return A(n);
}

int main() {
  // A a0(0);
  // A a1(1);
  // A a_ = a0;

  // not called operator= because of RVO(return value optimization)
  A a = MakeA(0);
}
