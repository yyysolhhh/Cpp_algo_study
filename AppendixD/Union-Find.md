때# Union-Find (Disjoint-set)

### 0x00 정의와 성질

Union 연산 - 두 그룹을 합치는 연산  
Find 연산 - 원소가 속해 있는 그룹을 알아내는 연산

### 0x01 Union 연산

Union u, v -> v의 루트를 u의 루트의 자식으로 만들기  
(u가 속한 트리의 루트를 찾고, v가 속한 트리의 루트를 찾은 후 v가 속한 트리의 루트를 u가 속한 트리의 루트의 자식으로 만들기)

### 0x02 Find 연산

```c++
vector<int> p(11, -1);

int find(int x) {
    if (p[x] < 0)
        return x;
    return find(p[x]);
}

int find(int x) {
    while (p[x] > 0)
        x = p[x];
    return x;
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    p[v] = u;
    return true;
}
```

find 함수 실행 시간이 전체 시간복잡도에 중요하게 작용  
최악의 경우 정점의 깊이가 최대 N  
최적화 적용하지 않으면 O(N)

### 0x03 최적화 기법

최적화 1 - Union by rank  
u가 속한 트리의 높이와 v가 속한 트리의 높이를 비교한 다음 더 낮은 트리를 높은 트리의 자식으로 붙이는 최적화

rank는 음수로 저장

```c++
bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (p[v] < p[u]) // v의 랭크가 더 큰 경우
        swap(u, v); // u, v를 swap
    // 위의 if문으로 인해 u의 랭크 >= v의 랭크이다
    if (p[u] == p[v]) // 랭크가 같은 경우 랭크를 1 증가시킴
        p[u]--;
    p[v] = u; // v를 u의 자식으로 만든다
    return true;
}
```

최적화 2 - 경로 압축  
find를 할 때 경로를 압축해 효율적으로 동작하게 만드는 방법  
지나가는 길에 있던 모든 정점을 모두 루트의 자식으로 만들기

```c++
int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}
```

시간복잡도
| | |
| - | - |
| 최적화 1 (Union by rank) | O(log N) |
| 최적화 2 (경로 압축) | Amortized O(log N) |
| 최적화 1 + 최적화 2 | Amortized O(α(N)) <br> ($N \leq 2^{2^{2^{65536}}} - 3$일 때 $α(N) \leq 4$) |

Amortized O(log N) - 연산 한 번 할 때는 운이 나쁘면 O(N)  
α는 애커만 역함수  
현실적으로 사용할 N의 범위에서는 사실상 상수 취급 하면 됨  
최적화 둘 중에 하나만 적용해도 시간 초과 발생할 가능성 거의 없음

### 0x04 연습 문제

BOJ 1717번: 집합의 표현

BOJ 7511번: 소셜 네트워킹 어플리케이션
