#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int numberOfDivisors(int n) {
  int divisors = 1;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      int power = 0;
      while (n % p == 0) {
        n /= p;
        ++power;
      }
      divisors *= (power + 1);
    }
  }
  if (n > 1)
    divisors *= 2;  // n is a prime factor itself
  return divisors;
}

int main() {
  int n = 36;

  cout << "Sum of all divisors of " << n << " : " << numberOfDivisors(n)
       << endl;

  return 0;
}
