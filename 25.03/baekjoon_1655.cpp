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
