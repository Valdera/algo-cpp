# Data Structures, Algorithms, and Problem Solutions in C++

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)
![Linux Build](https://github.com/Valdera/algo-cpp/workflows/Ubuntu%20CI%20Test/badge.svg)

## Software Requirements

- CMake 3.16+
- GNU Makefile
- Doxygen
- Conan (<= 2) or VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)
- Code Coverage (only on GNU|Clang): lcov, gcovr

## Default Solution Template

```c++
#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long int
#define ld long double
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)      \
  for (auto x : a)    \
    cout << x << " "; \
  cout << endl
#define print1(a)  \
  for (auto x : a) \
  cout << x.F << " " << x.S << endl
#define print2(a, x, y)       \
  for (int i = x; i < y; i++) \
    cout << a[i] << " ";      \
  cout << endl

using namespace std;

inline int power(int a, int b) {
  int x = 1;
  while (b) {
    if (b & 1)
      x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}  // NOLINT(*-reserved-identifier)

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1,
         Args&&... args)  // NOLINT(*-reserved-identifier)
{
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

const int N = 200005;

void solve() {}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen(SRC_PATH "/input.txt", "r", stdin);
  freopen(SRC_PATH "/output.txt", "w", stdout);
#endif

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
```


## Author

- **Fauzan Valdera** - [Valdera](https://github.com/Valdera)
