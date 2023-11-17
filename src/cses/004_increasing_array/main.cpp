/**
 * Problem:
 * https://cses.fi/problemset/task/1094
 */

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

// ----------------------<SHORT>--------------------------
#define F first
#define S second
#define ll long long int
#define ld long double
#define si set<long long int>
#define vi vector<long long int>
#define pii pair<long logng int, long long int>
#define vpi vector<pii>
#define vpp vector<pair<long long int, pii>>
#define mii map<long long int, long long int>
#define mci map<char, long long int>
#define mpi map<pii, long long int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((long long int)x.size())
#define all(p) p.begin(), p.end()
#define que_max priority_queue<long long int>
#define que_min priority_queue<long long int, vi, greater<long long int>>

#define REP(i, k, n) for (i = k; i < n; i++)
#define REPT(i, k, n) for (i = k; i <= n; i++)
#define REPR(i, k, n) for (i = k; i > n; i--)
#define REPRT(i, k, n) for (i = k; i >= n; i--)

// ----------------------</SHORT>--------------------------

// ----------------------<DEBUG>--------------------------
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

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
// ----------------------</DEBUG>--------------------------

// ----------------------<CONST>--------------------------

#define PI 3.1415926535897932384626433832795l

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int N = 200005;

// ----------------------</CONST>--------------------------

// ----------------------<MATH>---------------------------
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}

template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}

int add(int a, int b, int c = MOD) {
  int res = a + b;
  return (res >= c ? res - c : res);
}

int mod_neg(int a, int b, int c = MOD) {
  int res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}

int mul(int a, int b, int c = MOD) {
  ll res = (ll)a * b;
  return (res >= c ? res % c : res);
}

int muln(int a, int b, int c = MOD) {
  ll res = (ll)a * b;
  return ((res % c) + c) % c;
}

ll mulmod(ll a, ll b, ll m = MOD) {
  ll q = (ll)(((ld)a * (ld)b) / (ld)m);
  ll r = a * b - q * m;
  if (r > m)
    r %= m;
  if (r < 0)
    r += m;
  return r;
}

template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}

template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}

template <typename T>
T extended_euclid(T a, T b, T& x, T& y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}

template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}

// ----------------------</MATH>--------------------------

// ----------------------</BITWISE>--------------------------
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

// ----------------------</BITWISE END>--------------------------

void solve() {
  ll n;
  cin >> n;
  ll curr;
  ll prev;
  ll res = 0;

  for (int i = 0; i < n; i++) {
    cin >> curr;

    if (i > 0 && curr < prev) {
      res += prev - curr;
    } else {
      prev = curr;
    }
  }

  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen(SRC_PATH "/input.txt", "r", stdin);
  freopen(SRC_PATH "/output.txt", "w", stdout);
#endif

  clock_t z = clock();
  int t = 1;
  while (t--)
    solve();

  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
