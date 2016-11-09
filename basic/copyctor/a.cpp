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
 private:
  int n;
};

A MakeA(int n) {
  A a(n);  
  return a;
}

int main() {
  A a0(0);
  A a1(a0);
}
