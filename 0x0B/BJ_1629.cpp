#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// typedef long long ll;
using ll = long long;
ll A, B, C;
ll power(ll b) {
  if (b == 1) return A % C;
  ll val = power(b / 2);
  val = val * val % C;
  if (b % 2 == 0) return val;
  return val * A % C;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> C;
  cout << power(B);
}