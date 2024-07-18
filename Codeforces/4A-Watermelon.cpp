#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w;
  cin >> w;
  if ((w - 2) % 2 == 0 && w > 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}