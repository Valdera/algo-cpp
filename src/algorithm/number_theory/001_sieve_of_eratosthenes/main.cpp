#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<bool> sieve(int n) {
  // P[i] = true -> i is not prime
  // P[i] = false -> i is prime
  vector<bool> P(n + 1);

  P[0] = P[1] = true;
  int lim = (int)sqrt(double(n));
  for (int i = 2; i <= lim; i++) {
    if (!P[i]) {
      for (int j = i * i; j <= n; j += i) {
        P[j] = true;
      }
    }
  }

  return P;
}

int main() {

  vector<bool> sieve_till_101 = sieve(101);

  for (int i = 0; i < sieve_till_101.size(); i++) {
    cout << i << " is prime : " << !sieve_till_101[i] << endl;
  }

  return 0;
}
