#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) {
      cout << ' ';
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      cout << '*';
    }
    cout << '\n';
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = 1; j <= N - i; j++) {
      cout << ' ';
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      cout << '*';
    }
    cout << '\n';
  }
}