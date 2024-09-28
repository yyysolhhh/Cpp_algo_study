#include <bits/stdc++.h>
using namespace std;
// 내 풀이
int N, cnt;
int queen[15];
bool visited[15];
int is_dup(int cur, int i) {
  for (int j = 0; j < cur; j++) {
    if (queen[j] == i || j == cur || abs(queen[j] - i) == abs(cur - j))
      return 1;
  }
  return 0;
}
void nqueen(int cur) {
  if (cur == N) {
    cnt++;
    return;
  }
  for (int i = 0; i < N; i++) {
    if (visited[i] || is_dup(cur, i)) continue;
    queen[cur] = i;
    visited[i] = true;
    nqueen(cur + 1);
    visited[i] = false;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  nqueen(0);
  cout << cnt;
  return 0;
}

// 강의 풀이
bool isused1[40];
bool isused2[40];
bool isused3[40];
int cnt = 0;
int n;
void func(int cur) {
  if (cur == n) {
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;
    isused1[i] = 1;
    isused2[i + cur] = 1;
    isused3[cur - i + n - 1] = 1;
    func(cur + 1);
    isused1[i] = 0;
    isused2[i + cur] = 0;
    isused3[cur - i + n - 1] = 0;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
  return 0;
}