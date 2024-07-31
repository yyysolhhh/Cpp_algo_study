#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double M;
  cin >> M;
  cout << fixed;
  cout.precision(1);
  if (M <= 30) {
    cout << M / 2;
  } else {
    cout << M * 3 / 2 - 30;
    // 15 + (M - 30) * 3 / 2
  }
  return 0;
}