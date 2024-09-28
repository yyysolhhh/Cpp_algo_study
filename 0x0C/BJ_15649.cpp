#include <bits/stdc++.h>
using namespace std;
// 내 풀이
int N, M;
vector<int> perm;
void print() {
  for (int i = 0; i < M; i++) {
    cout << perm[i] << ' ';
  }
  cout << '\n';
}
void permutation() {
  if (perm.size() == M) {
    print();
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (find(perm.begin(), perm.end(), i) != perm.end()) continue;
    perm.push_back(i);
    permutation();
    perm.pop_back();
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  permutation();
  return 0;
}

// 강의 풀이
int n, m;
int arr[10];
bool isused[10];
void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!isused[i]) {
      arr[k] = i;
      isused[i] = 1;
      func(k + 1);
      isused[i] = 0;
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}