# 트리

### 0x00 정의와 성질

무방향이면서 사이클이 없는 연결 그래프 (Undirected Acyclic Connected Graph)

#### 트리 (Tree)

= 무방향이면서 사이클이 없는 연결 그래프 (Undirected Acyclic Connected Graph)  
= 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프  
= 임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)유일한 그래프  
= V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프  
= 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프  
= V개의 정점을 가지고 V-1개의 간선을 가지는 Acyclic(=사이클이 없는) 그래프

임의의 정점을 루트로 만들 수 있음

### 0x01 BFS, DFS

- BFS 예시 코드 1 - 부모 배열 채우기

```c++
vector<int> adj[10];
int p[10];
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}
```

시간 복잡도 O(V + E)인데 트리에서는 E = V - 1 => O(V)

- BFS 예시 코드 2 - 부모와 depth 배열 채우기

```c++
vector<int> adj[10];
int p[10];
int depth[10];
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}
```

- DFS 예시 코드 1 - 부모와 depth 배열 채우기, 비재귀

```c++
vector<int> adj[10];
int p[10];
int depth[10];
void dfs(int root) {
    stack<int> s;
    s.push(root);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}
```

- DFS 예시 코드 2 - 부모와 depth 배열 채우기, 재귀

```c++
vector<int> adj[10];
int p[10];
int depth[10];
void dfs(int cur) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}
```

스택 메모리가 1MB로 제한되어 있을 때 V가 대략 3만 이상일 때 일자 트리 모양에서 스택 메모리 한계 넘을 수 있음

- DFS 예시 코드 3 - 단순 순회, 재귀

```c++
vector<int> adj[10];
void dfs(int cur, int par) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (par == nxt) continue;
        dfs(nxt, cur);
    }
}
// call dfs(1, 0);
```

부모 배열이나 depth 배열 등을 저장할 필요 없고 단순 순회가 목적일 때

### 0x02 이진 트리의 순회

- 레벨 순회 (Level-order Traversal)

```c++
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void bfs() { // root = 1
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if (lc[cur]) q.push(lc[cur]);
        if (rc[cur]) q.push(rc[cur]);
    }
}
```

- 전위 순회 (Preorder Traversal)

1. 현재 정점을 방문한다.
2. 왼쪽 서브 트리를 전위 순회한다.
3. 오른쪽 서브 트리를 전위 순회한다.

```c++
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void preorder(int cur) {
    cout << cur << ' ';
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}
// preorder(1);
```

전위 순회는 dfs와 방문 순서가 동일

- 중위 순회 (Inorder Traversal)

1. 왼쪽 서브 트리를 중위 순회한다.
2. 현재 정점을 방문한다.
3. 오른쪽 서브 트리를 중위 순회한다.

```c++
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) inorder(rc[cur]);
}
// inorder(1);
```

- 후위 순회 (Postorder Traversal)

1. 왼쪽 서브 트리를 후위 순회한다.
2. 오른쪽 서브 트리를 후위 순회한다.
3. 현재 정점을 방문한다.

```c++
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << cur << ' ';
}
// postorder(1);
```

https://www.geeksforgeeks.org/dsa/if-you-are-given-two-traversal-sequences-can-you-construct-the-binary-tree/

### 0x03 연습 문제

BOJ 11725번: 트리의 부모 찾기

- 비재귀 DFS, BFS로도 구현해보기

BOJ 1991번: 트리 순회

트리DP 유형 - 재귀적인 처리를 통해 트리에서 DP를 하는 알고리즘 공부해보기
