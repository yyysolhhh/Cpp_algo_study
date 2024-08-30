// 틀림 - 큰수 연산
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long fibonacci[n + 1];
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }
  cout << fibonacci[n];
  return 0;
}