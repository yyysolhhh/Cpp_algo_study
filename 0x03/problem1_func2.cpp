#include <bits/stdc++.h>
using namespace std;

int temp[100];
int func2(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    if (temp[100 - arr[i]]) {
      return 1;
    }
    temp[arr[i]] = 1;
  }
  return 0;
}

int main() {
  int arr[] = {1, 52, 48};
  int arr2[] = {50, 42};
  int arr3[] = {4, 13, 63, 87};
  cout << func2(arr, 3) << endl;  // 1
  cout << func2(arr2, 2) << endl; // 0
  cout << func2(arr3, 4) << endl; // 1
}