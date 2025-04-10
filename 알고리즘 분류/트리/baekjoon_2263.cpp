#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<int> inorder, postorder;
unordered_map<int, int> inorder_index; // 값 -> 중위 인덱스

void build(int in_l, int in_r, int post_l, int post_r) {
    if (in_l > in_r || post_l > post_r) return;

    int root = postorder[post_r];
    cout << root << " "; // 전위 순회는 루트 먼저 출력

    int root_idx = inorder_index[root];
    int left_size = root_idx - in_l;

    // 왼쪽 서브트리
    build(in_l, root_idx - 1, post_l, post_l + left_size - 1);

    // 오른쪽 서브트리
    build(root_idx + 1, in_r, post_l + left_size, post_r - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    inorder.resize(N);
    postorder.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
        inorder_index[inorder[i]] = i; // 빠르게 root 위치 찾기 위해
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    build(0, N - 1, 0, N - 1);
    return 0;
}

// 백준 2263 : 트리의 순회
// 트리

// 해당 문제는 중위 순회, 후위 순회만 주어지고 이를 통해 전위 순회를 풀어 보는 문제이다.

// 핵심 코드는 루트를 찾고 루트를 기준으로 왼쪽 트리와 오른쪽 트리를 구분하고 이를 통해 전위 순회를 도는 것이다.
// 후위 순회는 왼쪽 노드 -> 오른쪽 노드 -> 루트 노드 순으로 진행한다. 따라서, 후위 순회의 맨 마지막 노드는 무조건 루트 노드가 될 것이다.
// 따라서, 이를 기반으로 중위 순회에서 루트 노드의 왼쪽 트리, 오른쪽 트리를 구분할 수 있을 것이다. -->  (왼쪽 트리) 루트 노드 (오른쪽 트리)
// 이를 기반으로 unordered map을 활용한 출력을 진행하면 된다.
// 만약, 그래서 계속 진행하며 해당 루트 노드를 출력하고 해당 루트노드에서의 왼쪽, 오른쪽 트리를 구분하여 차례로 출력하면 되는 것이다.
// 이를 재귀로 구현하여 계속 진행하면 쉽게 해결할 수 있었던 문제.

// 실행 시간 : 44ms