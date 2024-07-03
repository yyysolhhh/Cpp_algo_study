#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[500][500];
bool visited[500][500];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      cin >> board[x][y];
    }
  }
  int num_pic = 0;
  int max_area = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (board[x][y] != 1 || visited[x][y]) {
        continue;
      }
      queue<pair<int, int>> Q;
      visited[x][y] = 1;
      Q.push({x, y});
      num_pic++;
      int area = 0;
      while (!Q.empty()) {
        area++;
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
          }
          if (visited[nx][ny] || board[nx][ny] != 1) {
            continue;
          }
          visited[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      // if (area > max_area) {
      //   max_area = area;
      // }
      max_area = max(max_area, area);
    }
  }
  cout << num_pic << '\n' << max_area;
}