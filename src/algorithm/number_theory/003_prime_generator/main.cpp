#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> generatePrimes(int n) {
  vector<int> P{2, 3};

  for (int num = 5; num <= n; num += 2) {
    for (int i = 0; i < P.size(); i++) {
      if (num % P[i] == 0) {
        break;
      } else if (sqrt((double)num) < (double)P[i]) {
        P.push_back(num);
        break;
      }
    }
  }

  return P;
}

int main() {

  vector<int> primes_till_101 = generatePrimes(101);

  for (int num : primes_till_101) {
    cout << num << endl;
  }

  return 0;
}
