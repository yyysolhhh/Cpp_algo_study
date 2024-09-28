#include <bits/stdc++.h>
using namespace std;

void permutation() {
  int a[3] = {1, 2, 3};
  do {
    for (int i = 0; i < 3; i++) cout << a[i];
    cout << '\n';
  } while (next_permutation(a, a + 3));
}

void combination() {
  int a[4] = {0, 0, 1, 1};
  do {
    for (int i = 0; i < 4; i++) {
      if (a[i] == 0) cout << i + 1;
    }
    cout << '\n';
  } while (next_permutation(a, a + 4));
}

int main(void) {
  permutation();
  combination();
  return 0;
}