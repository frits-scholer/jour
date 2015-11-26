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
     for (size_t j=0;j<size;++j)// if (data[i][j]>=INT32_MAX>>1) std::cout << '-' << '\t';
       //else 
	   std::cout << data[i][j] << '\t';
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

//necessary for linkage
template void matrix<unsigned long>::getMatrix(const char *fname);
template void matrix<unsigned long>::printMatrix();

matrix<unsigned long> op(matrix<unsigned long> a, const matrix<unsigned long>& b) {return a*b;}
int main() {
  matrix<unsigned long> m(4);
  m.getMatrix("tetra.in");
  //m.printMatrix();
  matrix<unsigned long> pow(4);
  unsigned long long n;
  std::cin >> n;std::cout << n << std::endl;
  pow = power_semigroup(m,n, op);
  pow.printMatrix();
}
