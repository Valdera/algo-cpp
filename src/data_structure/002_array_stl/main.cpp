#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

void updateArray(array<int, 6>& arr, int i, int val) {
  arr[i] = val;
}

void print(const array<int, 6>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  array<int, 6> arr = {1, 2, 33, 14, 5, 6};

  updateArray(arr, 0, 1);

  sort(arr.begin(), arr.end());

  print(arr);

  array<int, 10> fives{};
  fives.fill(5);

  for (int five : fives) {
    cout << five << " ";
  }

  return 0;
}
