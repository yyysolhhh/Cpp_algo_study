#include <bits/stdc++.h>

using namespace std;

int func1(int N) {
  int i = 1;
  int sum = 0;
  while (i <= N) {
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
    i++;
  }
  return sum;
}

int func2(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] + arr[j] == 100)
        return 1;
    }
  }
  return 0;
}

int func3(int N) {
  for (int i = 0; i < N / 2; i++) {
    if (i * i == N)
      return 1;
  }
  return 0;
}

int main() {
  // int N;
  // cin >> N;
  // cout << func1(N);

  int arr[] = {1, 52, 48};
  int arr2[] = {50, 42};
  int arr3[] = {4, 13, 63, 87};
  cout << func2(arr, 3) << endl;  // 1
  cout << func2(arr2, 2) << endl; // 0
  cout << func2(arr3, 4) << endl; // 1

  cout << func3(9) << endl;         // 1
  cout << func3(693953651) << endl; // 0
  cout << func3(756580036) << endl; // 1
}