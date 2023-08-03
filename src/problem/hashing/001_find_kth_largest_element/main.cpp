/**
 * Problem:
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

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
#define mci map<char, int>
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

int firstUniqueChar(string s) {
  array<int, 26> m{};

  for (int c : s) {
    m.at(c - 'a') += 1;
  }

  for (int i = 0; i < s.size(); i++) {
    if (m.at(s[i] - 'a') == 1)
      return i;
  }

  return -1;
}

void solve() {
  string s;
  cin >> s;

  cout << firstUniqueChar(s) << endl;
}

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
  cin >> t;
  while (t--)
    solve();

  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
