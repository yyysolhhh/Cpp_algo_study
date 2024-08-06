#include <bits/stdc++.h>
using namespace std;

// 2
int solve(int n, int r, int c) {
  // int half = pow(2, n - 1);
  int half = 1 << (n - 1);
  if (n == 0) return 0;
  if (r < half && c < half) {
    return solve(n - 1, r, c);
  } else if (r < half && c >= half) {
    return solve(n - 1, r, c - half) + half * half;
  } else if (r >= half && c < half) {
    return solve(n - 1, r - half, c) + half * half * 2;
  } else {
    return solve(n - 1, r - half, c - half) + half * half * 3;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, r, c;
  cin >> N >> r >> c;
  cout << solve(N, r, c);
  return 0;
}

// 1
// int order;
// void solve(int size, int r, int c) {
//   if (size == 1) return;
//   if (r < size / 2 && c < size / 2) {
//     solve(size / 2, r, c);
//   } else if (r < size / 2 && c >= size / 2) {
//     order += size / 2 * size / 2;
//     solve(size / 2, r, c - size / 2);
//   } else if (r >= size / 2 && c < size / 2) {
//     order += size / 2 * size / 2 * 2;
//     solve(size / 2, r - size / 2, c);
//   } else {
//     order += size / 2 * size / 2 * 3;
//     solve(size / 2, r - size / 2, c - size / 2);
//   }
// }
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int N, r, c;
//   cin >> N >> r >> c;
//   int size = pow(2, N);
//   solve(size, r, c);
//   cout << order << '\n';
//   return 0;
// }