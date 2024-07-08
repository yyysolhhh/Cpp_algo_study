#include <bits/stdc++.h>
using namespace std;

void print_number(int n) {
  if (n == 0) return;
  cout << n << ' ';
  print_number(n - 1);
}

int calculate_sum(int n) {
  if (n == 0) return 0;
  return calculate_sum(n - 1) + n;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  print_number(n);
  cout << '\n' << calculate_sum(n);
  return 0;
}