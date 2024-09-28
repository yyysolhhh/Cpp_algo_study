# 백트래킹

### 0x00 알고리즘 설명
- 백트래킹: 현재 상테에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

### 0x01 연습 문제 1 - N과 M
- BOJ 15649: N과 M(1)

### 0x02 연습 문제 2 - N-Queen
- BOJ 9663: N-Queen  
A1에 퀸을 놓으면 바로 B1, B2에 퀸을 놓는 경우는 해볼 필요가 없어지는 것과 같은 상황을 백트래킹에서 가지치기라고 부름  
가지치기가 빈번하면 시간복잡도 가늠하기 힘듦  
가장 시간 오래 걸릴만한 케이스를 직접 돌려봐서 시간초과가 나는지 보면 됨  
시간을 로컬에서 측정할때는 release 모드로 실행해야함  
보통은 서버가 로컬보다 빠름  

### 0x03 연습 문제 3 - 부분수열의 합
- BOJ 1182: 부분수열의 합

### 0x04 STL next_permutation
https://cplusplus.com/reference/algorithm/next_permutation/
```c++
// 순열 사용 예시
int a[3] = {1, 2, 3};
do {
    for (int i = 0; i < 3; i++)
        cout << a[i];
    cout << '\n';
} while (next_permutation(a, a + 3));
/*
123
132
213
231
312
321
*/

// 조합
int a[4] = {0, 0, 1, 1};
// 5개중 3개 => {0, 0, 0, 1, 1}
do {
    for (int i = 0; i < 4; i++) {
        if (a[i] == 0)
            cout << i + 1;
    }
    cout << '\n';
} while (next_permutation(a, a + 4));
/*
12
13
14
23
24
34
*/
```

연습문제들 백트래킹으로 풀어보고 N과 M시리즈는 next_permutation으로도 풀어보기