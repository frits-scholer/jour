#include <iostream>
#include <functional>
#include "matrix.h"
#include "powerop.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <cstdlib>
#include "matrix.h"

template <typename T>
void matrix<T>::getMatrix(const char *fname) {
  std::ifstream fin(fname);
  for (size_t i=0;i<size;++i) {
    std::string row;
    std::getline(fin,row);
    std::istringstream is(row);
    for (size_t j = 0;j < size; ++j) {
      char buf[8];
      is >> buf;
      //is >> data[i][j];
      if (buf[0]== '*') data[i][j]=INT32_MAX>>1;
      else data[i][j]= std::atoi(buf);
    }
  }
  fin.close();
}

template <typename T>
void matrix<T>::printMatrix() {
   for (size_t i=0;i<size;++i) {
     for (size_t j=0;j<size;++j) if (data[i][j]>=INT32_MAX>>1) std::cout << '-' << '\t';
	 else std::cout << data[i][j] << '\t';
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

//necessary for linkage
template void matrix<int>::getMatrix(const char *fname);
template void matrix<int>::printMatrix();

matrix<int> op(matrix<int> a, const matrix<int>& b) {return a*b;}
int main() {
  matrix<int> m(4);
  m.getMatrix("tetra.in");
  m.printMatrix();
  matrix<int> pow(4);
  for (size_t n=2 ;n < 25; ++n) {
    pow = power_semigroup(m,n, op);
    pow.printMatrix();
  }
}