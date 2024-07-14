// bfs
#include <bits/stdc++.h>
using namespace std;
// 1
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int N;
//   cin >> N;
//   int count[N];
//   fill(count, count + N, -1);
//   queue<int> Q;
//   Q.push(N);
//   count[N] = 0;
//   while (!Q.empty()) {
//     double cur = Q.front();
//     Q.pop();
//     for (double next : {cur / 3, cur / 2, cur - 1}) {
//       if (next - int(next) != 0) continue;
//       if (count[int(next)] >= 0) continue;
//       count[int(next)] = count[int(cur)] + 1;
//       Q.push(next);
//     }
//   }
//   cout << count[1] << '\n';
// }

// 2
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int count[N + 1];
  fill(count, count + N + 1, -1);
  queue<int> Q;
  Q.push(1);
  count[1] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int next : {cur * 3, cur * 2, cur + 1}) {
      if (next > N || count[next] >= 0) continue;
      count[next] = count[cur] + 1;
      if (next == N) break;
      Q.push(next);
    }
  }
  cout << count[N];
}