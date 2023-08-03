#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {

  queue<string> q;

  q.push("C++");
  q.push("Java");
  q.push("Python");
  q.push("OS");

  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}
