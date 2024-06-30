#include <bits/stdc++.h>
using namespace std;

// 메모리 2020KB
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B - C << '\n';
  cout << stoi(to_string(A) + to_string(B)) - C;
  return 0;
}

// 메모리 2024KB
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string A, B, C;
  cin >> A >> B >> C;
  cout << stoi(A) + stoi(B) - stoi(C) << '\n';
  cout << stoi(A + B) - stoi(C);
  return 0;
}