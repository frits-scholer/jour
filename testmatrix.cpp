#include <iostream>
#include "matrix.h"

int main() {
  matrix<int> m(4);
  m.getMatrix("matrix.in");
  m.printMatrix();
  matrix<int>prod = m*m;
  prod.printMatrix();
  prod = m*m*m;
  prod.printMatrix();
  prod = m*m*m*m;
  prod.printMatrix();
}
