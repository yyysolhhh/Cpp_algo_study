// 1
#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[100001];
const int INF = 0x7fffffff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);
  int ans = INF;
  int st = 0, en = 0;
  while (true) {
    if (en == N) break;
    if (A[en] - A[st] < M)
      en++;
    else {
      ans = min(ans, A[en] - A[st]);
      st++;
    }
  }
  cout << ans;
  return 0;
}

// 2
#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[100001];
int ans = 0x7fffffff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);
  int en = 0;
  for (int st = 0; st < N; st++) {
    while (en < N && A[en] - A[st] < M) en++;
    if (en == N) break;
    ans = min(ans, A[en] - A[st]);
  }
  cout << ans;
  return 0;
}