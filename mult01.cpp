#include <iostream>
inline bool odd(int x) {return x & 1;}
inline int half(int x) {return x >> 1;}

int multiply1(int n, int a) {
  if (n==1) return a;
  int result = multiply1(half(n), a + a);
  if (odd(n)) result += a;
  return result;
}

int mult_acc1(int r, int n, int a) {
  if (n==1) return r + a;
  if (odd(n)) r += a;
  return mult_acc1(r, half(n), a + a);
}

int mult_acc3(int r, int n, int a) {
  if (odd(n)) {
    r += a;
    if (n==1) return r;
  }
  n = half(n);
  a += a;
  return mult_acc3(r, n, a);
}

int mult_acc4(int r, int n, int a) {
  while (true) {
    if (odd(n)) {
      r += a;
      if (n==1) return r;
    }
    n = half(n);
    a += a;
  }
}

int multiply2(int n, int a) {
  if (n==1) return a;
  return mult_acc4(a, n-1, a);
}

int multiply3(int n, int a) {
  while (!odd(n)) {
    a += a;
    n = half(n);
  }
  if (n==1) return a;
  return mult_acc4(a, n-1, a);
}

int multiply4(int n, int a) {
  while (!odd(n)) {
    a += a;
    n = half(n);
  }
  if (n==1) return a;
  return mult_acc4(a, half(n-1), a + a);
}

int main() {
  std::cout << multiply1(73147, 8549) << "\n";
  std::cout << mult_acc3(0,73147, 8549) << "\n";
  std::cout << multiply4(32, 64) << "\n";
}
