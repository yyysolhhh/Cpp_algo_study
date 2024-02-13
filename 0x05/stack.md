# Stack

FILO(First In Last Out)
스택, 큐, 덱 - Restricted Structure

- 스택의 성질

  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 상단의 원소 확인이 O(1)
  4. 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

- STL stack
  ```c++
  stack<int> S;
  S.push(10);
  cout << S.pop();
  cout << S.top();
  cout << S.empty();
  cout << S.size();
  ```
  스택이 비어있을때 pop, top 호출하면 runtime error
