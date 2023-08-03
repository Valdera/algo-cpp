#include <algorithm>
#include <iostream>

using namespace std;

// Array is passed by reference
void updateArray(int arr[], int i, int val) {
  arr[i] = val;
}

void print(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ",";
  }
}

int main() {

  int arr[] = {1, 5, 4, 3, 2};
  int n = sizeof(arr) / sizeof(int);

  updateArray(arr, 1, 13);

  sort(arr, arr + n);

  print(arr, n);

  return 0;
}
