# Deque(double ended queue)

restricted structure의 끝판왕
양쪽 끝에서 삽입 삭제 전부 가능

- 덱의 성질

  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 앞/뒤의 원소 확인이 O(1)
  4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
     STL deque에서는 인덱스로 접근할 수 있음.

- STL deque

  ```c++
    deque<int> DQ;
    DQ.push_front();
    DQ.push_back();
    DQ.pop_front();
    DQ.pop_back();
    DQ.empty();
    DQ.size();
    DQ.back();
    DQ.front();
    DQ.insert(DQ.begin() + 1, x);
    DQ.erase(DQ.begin() + 3)
  ```

vector와 달리 deque는 모든 원소들이 메모리 상에 연속으로 배치되어 있지 않음.
앞과 뒤에서의 추가와 제거가 모두 필요하면 STL deque 사용.
굳이 필요하지 않고 배열과 같은 느낌으로 쓰고싶을 땐 STL vector 사용.
