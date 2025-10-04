# 다익스트라

### 0x00 알고리즘 설명

- 다익스트라 알고리즘 = 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘
- 음수 간선이 있으면 사용할 수 없음 -> 벨만포드 알고리즘
- 길 찾기 알고리즘 대표적인 예시 - A\*(A star) 알고리즘 - 현실적으로 다익스트라 사용하기 어려울 때 사용하는 근사 알고리즘

### 0x01 구현

- 매 단계마다 도달할 수 있는 정점 중에서 시작점으로부터의 거리가 가장 가까운 정점을 구해서 그 거리를 확정하는 방식으로 동작
- 매 단계마다 간선을 다 훑을 경우 O(VE)
- 새 정점 추가할 때마다 미리 테이블에 거리 계산해두고 거기서 최솟값 찾는 방식 O(V^2+E) - 더 효율적

```c++
// 비효율적인 방법
// (비용, 간선 번호)
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int V = 10;
void dijkstra_naive(int st) {
    fill(d, d + V + 1, INF); // 최단 거리 테이블 초기화
    d[st] = 0;
    while (true) {
        int idx = -1;
        for (int i = 1; i <= V; i++) {
            if (fix[i]) continue;
            if (idx == -1) idx = i;
            else if (d[i] < d[idx]) idx = i;
        }
        if (idx == -1 || d[idx] == INF) // 더 이상 선택할 정점이 없으면
            break;
        fix[idx] = 1; // 정점 idx 고정
        for (auto nxt : adj[idx])
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
    }
}
```

##### 우선순위 큐를 이용한 다익스트라 알고리즘

1. 우선순위 큐에 (0, 시작점)을 추가
2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 넘어감
3. 원소가 가리키는 정점을 v라고 할 때, v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 것이 더 작은 값을 가질 경우 최단 거리 테이블의 값을 갱신하고 우선순위 큐에 (거리, 이웃한 정점의 번호)를 추가
4. 우선순위 큐가 빌 때까지 2, 3번 과정을 반복

- 거리가 확정되었는지 별도로 관리할 필요 없음
- 시간 복잡도는 간선 1개당 최대 1개 원소가 추가될 수 있기 때문에 (ElgE)

BOJ 1753번: 최단 경로

```c++
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, st;

// (비용, 정점 번호)
vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int d[20005]; // 최단 거리 테이블
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    d[st] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}
        // 거리가 d에 있는 값과 다를 경우 넘어감
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            // cur를 거쳐가는 것이 더 작은 값을 가질 경우
            // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}
```

### 0x02 경로 복원 방법

BOJ 11779번: 최소비용 구하기 2

```c++
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, st, en;

// (비용, 정점 번호)
vector<pair<int, int>> adj[1005];
const int INF = 1e9 + 10;
int d[1005]; // 최단 거리 테이블
int pre[1005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    fill(d, d + v + 1, INF);
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    d[st] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << '\n';
    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (auto x : path) cout << x << ' ';
}
```
