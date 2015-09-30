#include <iostream>
#define NonCommutativeAdditiveSemigroup typename
#define Integer typename
#define NonCommutativeAdditiveMonoid typename
#define AdditiveGroup typename

template <typename A>
inline bool odd(A x) {return x & 1;}
template <typename A>
inline int half(A x) {return x >> 1;}

template <NonCommutativeAdditiveSemigroup A, Integer N>
A multiply_accumulate_semigroup(A r, N n, A a) {
  //precondition(n>=0);
  if (n==0) return r;
  while (true) {
    if (odd(n)) {
      r += a;
      if (n==1) return r;
    }
    n = half(n);
    a += a;
  }
}

template <NonCommutativeAdditiveSemigroup A, Integer N>
A multiply_semigroup(N n, A a) {
  //  precondition(n > 0);
  while(!odd(n)) {
    a += a;
    n = half(n);
  }
  if (n == 1) return a;
  return multiply_accumulate_semigroup
    (a, half(n-1), a + a);
}

template <NonCommutativeAdditiveMonoid A, Integer N>
A multiply_monoid(N n, A a) {
  //precondition(n>=0);
  if (n == 0) return A(0);
  return multiply_semigroup(n, a);
}

template <AdditiveGroup A, Integer N>
A multiply_group(N n, A a) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return multiply_monoid(n, a);
}

