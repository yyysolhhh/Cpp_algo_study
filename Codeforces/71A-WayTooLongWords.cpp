#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string word;
    cin >> word;
    int len = word.length();
    if (len > 10) {
      cout << word[0] << len - 2 << word[len - 1] << '\n';
    } else {
      cout << word << '\n';
    }
  }
}