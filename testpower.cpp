#include <iostream>
#include <functional>
#include "matrix.h"
#include "powerop.h"
matrix<int> op(matrix<int> a, const matrix<int>& b) {return a*b;}
int main() {
  matrix<int> m(2);
  m.getMatrix("fib.in");
  m.printMatrix();
  matrix<int> pow(2);
  for (size_t n=2 ;n < 25; ++n) {
    pow = power_semigroup(m,n, op);
    pow.printMatrix();
  }
}
