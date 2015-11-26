#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <algorithm>
#include <numeric>
//set up nxn matrices of integers

template <typename T>
class matrix {
 size_t size;
 std::vector<std::vector<T> > data;
 public:
 matrix(size_t n) : size(n) {
     for (size_t i=0;i<n;++i) {
       data.push_back(std::vector<T>(n));
     data[i] = std::vector<T>(n, T{0}); 
     }
 }
 T operator()(size_t i, size_t j) {return data[i][j];}
 matrix operator*(const matrix& b) {
   matrix a(size);
   for (size_t i=0;i<size;++i) 
     for (size_t j=0;j<size;++j) {
       std::vector<T> prod;
       for (size_t k=0;k<size;++k)
	 prod.push_back((data[i][k] * b.data[k][j])%1000000007UL);
       a.data[i][j] = std::accumulate(prod.begin(), prod.end(), a.data[i][j])%1000000007UL;
     }
   return a;
 }
 matrix min_op(const matrix& b) {
   matrix a(size);
   for (size_t i=0;i<size;++i) 
     for (size_t j=0;j<size;++j) {
       std::vector<T> prod;
       for (size_t k=0;k<size;++k)
	 prod.push_back(data[i][k] + b.data[k][j]);
       a.data[i][j] = *std::min_element(prod.begin(), prod.end());
     }
   return a;
 }
 void getMatrix(const char *fname);
 void printMatrix();
};

#endif
