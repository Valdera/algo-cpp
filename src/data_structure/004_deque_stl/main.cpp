#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {

  // Empty Container Constructor
  deque<int> first;

  // Fill Constructor (4 integers with value 100)
  deque<int> second(4, 100);

  // Range Constructor
  deque<int> third(second.begin(), second.end());

  // Copy Constructor
  deque<int> fourth(third);

  /********************************************/

  deque<int> dq;

  // push an element to the back
  dq.push_back(10);

  // remove element from the back
  dq.pop_back();

  // push an element to the front
  dq.push_front(30);

  // remove element from the front
  dq.pop_front();

  return 0;
}
