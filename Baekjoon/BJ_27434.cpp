// 틀림
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  long long ans = 1;
  while (N > 0) {
    ans *= N;
    N--;
  }
  cout << ans;
  return 0;
}