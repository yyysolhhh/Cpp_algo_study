// unsolved
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  list<int> L;
  for (int i = 0; i < N; i++)
    L.push_back(i);
  list<int>::iterator p = L.begin();
  cout << '<';
  while (N--) {
    // p += K % N;
    cout << *p << ", ";
    L.erase(p);
  }
  cout << '>';
}
