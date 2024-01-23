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
  for (int i = 1; i * i <= N; i++) {
    if (i * i == N)
      return 1;
  }
  return 0;
}

int func4(int N) {
  int res;
  for (int i = 1; i <= N; i *= 2) {
    res = i;
  }
  return res;
}

int main() {
  // int N;
  // cin >> N;
  // cout << func1(N);

  // // func1
  // cout << func1(16) << endl;    // 60
  // cout << func1(34567) << endl; // 278812814
  // cout << func1(27639) << endl; // 178254968

  // // func2
  // int arr[] = {1, 52, 48};
  // int arr2[] = {50, 42};
  // int arr3[] = {4, 13, 63, 87};
  // cout << func2(arr, 3) << endl;  // 1
  // cout << func2(arr2, 2) << endl; // 0
  // cout << func2(arr3, 4) << endl; // 1

  // // func3
  // cout << func3(9) << endl;         // 1
  // cout << func3(693953651) << endl; // 0
  // cout << func3(756580036) << endl; // 1

  // func4
  cout << func4(5) << endl;        // 4
  cout << func4(97615282) << endl; // 67108864
  cout << func4(1024) << endl;     // 1024
}