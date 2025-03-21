#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> maxHeap; // 최대 힙 (default: 큰 값이 루트)
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙 (default: 작은 값이 루트)

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 1. 최대 힙에 우선 삽입
        maxHeap.push(num);

        // 2. 최대 힙의 루트 값이 최소 힙의 루트 값보다 크면 교환
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // 3. 크기 조정 (최대 힙이 최소 힙보다 크거나 같도록 유지)
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 4. 중앙값 출력 (최대 힙의 루트 값)
        if (maxHeap.size() < minHeap.size()) cout << minHeap.top() << '\n';
        else cout << maxHeap.top() << '\n';
    }

    return 0;
}

// 1655 : pq, 구현 문제
// 해당 문제는 계속 가운데에 위치한 숫자를 찾는 문제이다.
// 만약 일반적인 q나 vector를 사용하게 된다면 정렬을 지속적으로 해 주어야 순서가 정렬이 된다. 하지만 이 경우, 시간 초과가 날 것이다. (주어진 시간 0.1초)
// 따라서, 이를 해결하지 위하여 priority queue를 사용하였다.
// priority queue는 기본적으로 내림차순 정렬이다.
// 따라서, 만약 오름차순으로 다시 정렬하고 싶다면  priority_queue<int, vector<int>, greater<int>> minHeap; 해당 코드처럼 선언을 해 주어야 오름차순으로 정렬이된다.
// 구초체 안에서 

// 실행시간 : 10ms