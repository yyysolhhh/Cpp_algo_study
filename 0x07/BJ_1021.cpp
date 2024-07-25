#include <bits/stdc++.h>
using namespace std;

// 1
deque<int> dq;
void operate() {
  int temp;
  temp = dq.front();
  dq.pop_front();
  dq.push_back(temp);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    dq.push_back(i);
  }
  while (M--) {
    int pos;
    cin >> pos;
    int cnt = 0;
    int len = dq.size();
    while (true) {
      if (dq.front() == pos) {
        dq.pop_front();
        break;
      }
      operate();
      cnt++;
    }
    if (cnt <= len / 2) {
      ans += cnt;
    } else {
      ans += len - cnt;
    }
  }
  cout << ans;
  return 0;
}

// 2
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int N, M;
//   cin >> N >> M;
//   deque<int> dq;
//   for (int i = 1; i <= N; i++) {
//     dq.push_back(i);
//   }
//   int ans = 0;
//   while (M--) {
//     int t;
//     cin >> t;
//     int idx = find(dq.begin(), dq.end(), t) - dq.begin();
//     while (dq.front() != t) {
//       if (idx < dq.size() - idx) {
//         dq.push_back(dq.front());
//         dq.pop_front();
//       } else {
//         dq.push_front(dq.back());
//         dq.pop_back();
//       }
//       ans++;
//     }
//     dq.pop_front();
//   }
//   cout << ans;
//   return 0;
// }