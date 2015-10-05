#include <iostream>
#include <functional>
#include "matrix.h"
#include "powerop.h"
matrix<int> op(matrix<int> a, const matrix<int>& b) {return a.min_op(b);}
int main() {
  matrix<int> m(4);
  m.getMatrix("matrix2.in");
  m.printMatrix();
  matrix<int> pow(4);
  for (size_t n=2 ;n < 4; ++n) {
    pow = power_semigroup(m,n, op);
    pow.printMatrix();
  }
}
