## 시간초과

어느 블로그에서 enqueue, dequeue할때 unavailable space가 발생하여 이걸 방지하기 위해 왼쪽으로
shift한다는 것을 보고 그렇게 구현했으나 시간초과 발생

## 해결책

일단 Array로 구현안하고 linked list로 구현하여 enqueue, dequeue과정을 O(1)으로 처리
