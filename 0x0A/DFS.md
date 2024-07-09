# DFS

### 0x00 알고리즘 설명
- DFS(Depth First Search)  
    다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘

### 0x01 예시
1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남김
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 2번을 반복  

모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)  
큐를 쓰면 BFS, 스택을 쓰면 DFS가 됨

### 0x02 BFS vs DFS
BFS - 현재 보는 칸으로부터 추가되는 인접한 칸은 거리가 현재 보는 칸보다 1만큼 더 떨어져있음  
거리 측정은 BFS만 가능  
거리 계산할 때는 DFS 사용할 수 없음  
그래프와 트리 자료구조에서 DFS 필요  