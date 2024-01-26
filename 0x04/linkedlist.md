## 연결리스트 성질

1. k번째 원소를 확인/변경하기 위해 O(k)가 필요함
2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1)
3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉬움

## 연결 리스트의 종류

- 단일 연결 리스트(Singly Linked List)
- 이중 연결 리스트(Doubly Linked List) - 메모리 더 씀
- 원형 연결 리스트(Circular Linked List)

배열과 연결리스트는 선형 자료구조
| | 배열 | 연결 리스트 |
|-|-|-|
| k번째 원소의 접근 | O(1) | O(k) |
| 임의 위치에 원소 추가/제거 | O(N) | O(1) |
| 메모리 상의 배치 | 연속 | 불연속 |
| 추가적으로 필요한 공간(Overhead) | - | O(N) |

메모장 커서가 가리키는 위치에 글자를 지우거나 추가함 - 연결리스트로 구현할 경우 효율적

``` c++
// 정석적인 구현
struct NODE {
    struct NODE *prev, *next;
    int data;
}
```

``` c++
// 코딩테스트에서는 STL list 쓰면 됨 (Doubly Linked List)
// STL 허용하지 않으면 아래 방법
// 메모리 누수 문제 있음
// 0번째 더미노드 만들기
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;
fill(pre, pre + MX, -1);
fill(nxt, nxt + MX, -1);

```
