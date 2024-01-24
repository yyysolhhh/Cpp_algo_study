#include <bits/stdc++.h>
using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n, x, t;
//   cin >> n >> x;
//   while (n--) {
//     cin >> t;
//     if (t < x) cout << t << ' ';
//   }
// }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, X;
  cin >> N >> X;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    if (A[i] < X) cout << A[i] << ' ';
  }
}

// int main(void) {
//   int N, X;
//   cin >> N >> X;

//   int A[N];
//   for (int i = 0; i < N; i++) {
//     scanf("%d", &A[i]);
//   }
//   for (int i = 0; i < N; i++) {
//     if (A[i] < X)
//       cout << A[i] << " ";
//   }
// }