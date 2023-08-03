#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  // Empty Container Constructor
  vector<int> first{};

  // Fill Constructor (4 integers with value 20)
  vector<int> second(4, 20);

  // Range Constructor
  int numbers[] = {10, 20, 30, 40};
  vector<int> third{numbers, numbers + 4};

  // Copy Constructor
  vector<int> fourth(third);

  /********************************************/

  vector<int> arr = {1, 2, 3, 4, 5};

  // Get element at index i
  cout << arr[1] << endl;
  cout << arr.at(1) << endl;

  // Get the current size
  cout << arr.size() << endl;

  // Get the underlying capacity;
  cout << arr.capacity() << endl;

  // push_back method O(1)
  arr.push_back(4);

  // pop_back method O(1)
  arr.pop_back();

  // clear all elements, reduce the size to 0
  arr.clear();

  // erase the 4th element
  arr.erase(arr.begin() + 4);

  // erase the range - first 3 elements
  arr.erase(arr.begin(), arr.begin() + 3);

  return 0;
}
