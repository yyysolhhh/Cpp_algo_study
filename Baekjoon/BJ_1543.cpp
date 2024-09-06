#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string doc, word;
  getline(cin, doc);
  getline(cin, word);
  int j = 0, ans = 0;
  for (int i = 0; i < doc.length(); i++) {
    bool flag = true;
    for (int j = 0; j < word.length(); j++) {
      if (doc[i + j] != word[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans++;
      i += word.length() - 1;
    }
  }
  cout << ans;
  return 0;
}

// 틀림
// #include <bits/stdc++.h>
// using namespace std;
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   string doc, word;
//   getline(cin, doc);
//   getline(cin, word);
//   int j = 0, ans = 0;
//   for (int i = 0; i < doc.length(); i++) {
//     cout << i << ' ' << ' ' << j << ' ' << doc[i] << ' ' << word[j] <<
//     '\n'; if (doc[i] == word[j]) {
//       if (j == word.length() - 1) {
//         j = 0;
//         ans++;
//         continue;
//       }
//       j++;
//     } else {
//       j = 0;
//     }
//   }
//   cout << ans;
//   return 0;
// }