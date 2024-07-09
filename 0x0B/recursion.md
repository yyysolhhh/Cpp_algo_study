# 재귀

0x00 알고리즘 설명
    
- 재귀: 하나의 함수에서 자기 자신을 다시 호출해 작업을 수행하는 알고리즘
    
```c++
void func1(int n) {
    if (n == 0) return;
    cout << n << ' ';
    func1(n - 1);
}
```
    - 절차지향적 사고
        3 출력
        func1(2) 호출
        2 출력
        func1(1) 호출
        1 출력
        func1(0) 호출
    
    - 귀납적 사고
        func1(1)이 1을 출력한다.
        func1(k)가 k k-1 k-2 ... 1을 출력하면
        func1(k+1)은 k+1 k k-1 ... 1을 출력한다.
    
- 재귀 함수의 조건
    - 특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어야 함(Base condition)
    - 모든 입력은 base condition으로 수렴해야 함

- 재귀에 대한 정보 1
    - 함수의 인자로 어떤 것을 받고 어디까지 계산한 수 자기 자신에게 넘겨줄지 명확하게 정해야 함
    - 모든 재귀 함수는 반복문만으로 동일한 동작을 하는 함수를 만들 수 있음
    - 재귀는 반복문으로 구현했을 때에 비해 코드가 간결하지만 메모리/시간에서는 손해를 봄

- 재귀에 대한 정보 2
    - 한 함수가 자기 자신을 여러 번 호출하게 되면 비효율적일 수 있음
    ```c++
        int fibo(int n) {
            if (n <= 1) return 1;
            return fibo(n - 1) + fibo(n - 2);
        }
    ```
        이 재귀 함수의 시간복잡도는 O(1.618^n)  
        손으로 계산하는 것보다 훨씬 느림  
        이미 계산한걸 또 계산함
        이 문제는 다이나믹 프로그래밍으로 O(n)에 해결할 수 있음

- 재귀에 대한 정보 3
    - 재귀 함수가 자기 자신을 부를 때 스택 영역에 계속 누적이 됨

    |       |
    |:-----:|
    | Code  |
    | Data  |
    | BSS   |
    | Heap  |
    | Stack |

    ```c++
    #include <bits/stdc++.h>
    using namespace std;

    void func(int a) {
        if (a == 0) return;
        func(a - 1);
    }

    int main() {
        func(100000);
        cout << "done";
    }
    ```
    - 일부 컴파일 환경에서는 스택 영역의 메모리가 별도로 1MB로 제한되어 있기도 함.
        - Visual Studio 2017/2019, GCC+MingW 1MB
        - Linux 버전에따라 8MB 혹은 10MB 제한
        - BOJ는 스택 메모리 제한 없음
        - swexpertacademy.com 제한 걸려있음
        - 스택 메모리에는 지역 변수도 들어감
        - BOJ에서 통과한 코드 로컬에서 계속 런타임 에러나면 재귀가 너무 깊거나 지역 변수로 int arr[2000][2000]과 같이 큰 배열을 잡았을 수 경우 의심
        - 스택 메모리 제한 해제하는 걸 추천


0x01 연습 문제 1 - 거듭제곱  
    
    a^b mod m

```c++
int func1(int a, int b, int m) {
    int val = 1;
    while (b--) val *= a;
    return val % m;
}
```

    int overflow
    중간 중간 계속 m으로 나눠서 나머지만 챙겨가면 됨

```c++
// int overflow 고려한 코드 - O(b)
using ll = long long;
ll func1(ll a, ll b, ll m) {
    ll val = 1;
    while (b--) val = val * a % m;
    return val;
}
```
    m이 2^23보다 크다면 long long 범위도 넘을 수 있음. 이런 상황에서는 Big Integer 기능이 있는 Java 또는 Python을 사용하거나 __int128을 써야함.

- BOJ 1629: 곱셈

0x02 연습 문제 2 - 하노이 탑
0x03 연습 문제 3 - Z