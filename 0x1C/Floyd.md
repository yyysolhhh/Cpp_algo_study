# 플로이드 알고리즘

### 0x00 알고리즘 설명

모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘  
방향, 무방향 상관 없음.  
음수 간선 가능. 음수 사이클은 문제 생김.
시간 복잡도: O(V^3)

### 0x01 구현

BOJ 11404번: 플로이드

```c++
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; // INF 두개 더할때 int overflow 안나게 하기 위해
int d[105][105];
int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + 1 + n, INF);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // if로 하는게 시간상 더 유리 - 상수 시간 최적화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}
```

정점 1000개까지는 플로이드로 풀어볼만 함

### 0x02 경로 복원 방법

BOJ 11780번: 플로이드 2

```c++
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + 1 + n, INF);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    nxt[i][j] = nxt[i][k];
                }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
    }
    cout << '\n';

    // 경로 복원
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (auto x : path) cout << x << ' ';
            cout << '\n';
    }
}
```

#### 정리

무방향, 방향 그래프에서 모든 정정 쌍 사이의 최단거리와 그 경로를 O(V^3)에 알아낼 수 있는 알고리즘.  
정점 수 1000개 이하
