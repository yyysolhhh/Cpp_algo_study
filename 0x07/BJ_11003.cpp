#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, L;
  cin >> N >> L;
  deque<pair<int, int>> dq;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    while (!dq.empty() && num <= dq.back().second) {
      dq.pop_back();
    }
    dq.push_back({i, num});
    if (dq.front().first <= i - L) {
      dq.pop_front();
    }
    cout << dq.front().second << ' ';
  }
  return 0;
}

// 시간 초과
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int N, L;
//   cin >> N >> L;
//   deque<int> A;
//   deque<int> dq;
//   for (int i = 0; i < N; i++) {
//     int a;
//     cin >> a;
//     A.push_back(a);
//   }
//   for (int i = 0; i < N; i++) {
//     dq.push_back(A.front());
//     if (dq.size() > L) dq.pop_front();
//     A.pop_front();
//     cout << *min_element(dq.begin(), dq.end()) << ' ';
//   }
//   return 0;
// }