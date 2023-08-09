#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<bool> segmentedSieve(int l, int r) {
  int lim = (int)sqrt(r);

  // mark[i] = true -> i is not prime
  // mark[i] = false -> i is prime
  vector<bool> mark(lim + 1, false);

  vector<int> primes;

  for (int i = 2; i <= lim; ++i) {
    if (!mark[i]) {
      primes.emplace_back(i);
      for (int j = i * i; j <= lim; j += i)
        mark[j] = true;
    }
  }

  // P[i] = true -> i is not prime
  // P[i] = false -> i is prime
  vector<bool> P(r - l + 1, false);
  for (int i : primes) {
    for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
      P[j - l] = true;
  }

  if (l == 1)
    P[0] = true;

  return P;
}

int main() {
  int l = 51;
  int r = 101;

  vector<bool> sieve_till_101 = segmentedSieve(l, r);

  for (int i = 0; i < sieve_till_101.size(); i++) {
    cout << l + i << " is prime : " << !sieve_till_101[i] << endl;
  }

  return 0;
}
