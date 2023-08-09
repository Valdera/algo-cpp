#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long sumOfAllDivisors(long long n) {
  long long sum = 1;
  for (long long p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      long long power = 0;
      while (n % p == 0) {
        n /= p;
        ++power;
      }
      sum *= (long long)(pow(p, power + 1) - 1) / (p - 1);
    }
  }
  if (n > 1)
    sum *= (n + 1);
  return sum;
}

int main() {
  int n = 36;

  cout << "Sum of all divisors of " << n << " : " << sumOfAllDivisors(n)
       << endl;

  return 0;
}
