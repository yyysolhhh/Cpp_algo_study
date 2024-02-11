FIFO(First in First Out)

- 큐의 성질

  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 앞/뒤의 원소 확인이 O(1)
  4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

- STL queue

  ```c++
    queue<int> Q;
    Q.push();
    Q.pop();
    Q.size();
    Q.front();
    Q.back();
    Q.empty();
  ```

큐 비어있을때 front, back, pop호출하면 runtime error
