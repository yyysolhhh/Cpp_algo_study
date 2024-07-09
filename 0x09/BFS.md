# BFS

### 0x00 알고리즘 설명
- BFS(Breadth First Search)  
    다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘

### 0x01 예시
1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김
2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
4. 큐가 빌 때까지 2번을 반복  

모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)

    https://cplusplus.com/reference/utility/pair/pair/

- 자주 실수하는 점
    1. 시작점에 방문했다는 표시를 남기지 않는다.  
    -> 시작점을 두 번 방문할 수 있음
    2. 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때 방문했다는 표시를 남겼다.  
    -> 같은 칸이 큐에 여러 번 들어가게 되어서 시간 초과나 메모리 초과 발생할 수 있음. 예제에서는 잘 돌아가다가 실제 제출했을 때 터지는 경우가 많아서 주의해야함.
    3. 이웃한 원소가 범위를 벗어났는지에 대한 체크를 잘못했다. 
    
    BOJ 1926: 그림 

### 0x02 응용1 - 거리 측정
    BOJ 2178: 미로 탐색

### 0x03 응용2 - 시작점이 여러 개일 때
    BOJ 7576: 토마토
    BOJ 7569: 토마토
    큐에 쌓이는 순서는 거리순

### 0x04 응용3 - 시작점이 두 종류일 때
    BOJ 4179: 불! 
    (BOJ 18809는 한가지를 먼저 다 진행시킬수 없는 경우)

### 0x05 응용4 - 1차원에서의 BFS
    BOJ 1697: 숨바꼭질 
    range-based for 이용