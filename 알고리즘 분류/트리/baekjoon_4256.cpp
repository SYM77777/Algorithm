#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> inorder_idx;
vector<int> pre_order;
vector<int> in_order;


void build(int pre_l, int pre_r, int in_l, int in_r) {

	if (in_l > in_r || pre_l > pre_r) return;


	int root = pre_order[pre_l];

	int root_idx = inorder_idx[root];
	int left_size = root_idx - in_l; // 왼쪽 트리의 크기

	// 왼쪽 트리
	build(pre_l + 1, pre_r + left_size, in_l, root_idx - 1);

	// 오른쪽 트리
	build(pre_l + left_size + 1, pre_r, root_idx + 1, in_r);

	// 루트는 출력
	cout << root << " ";

}


int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		inorder_idx.clear();
		pre_order.clear();
		in_order.clear();
		
		int node_num;
		cin >> node_num;

		pre_order.resize(node_num);
		in_order.resize(node_num);

		for (int i = 0; i < node_num; i++) {
			cin >> pre_order[i];
		}

		for (int i = 0; i < node_num; i++) {
			cin >> in_order[i];
			inorder_idx[in_order[i]] = i;
		}

		build(0, node_num - 1, 0, node_num - 1);
		cout << "\n";
	}

	return 0;
}


// 백준 4256 : 트리
// 트리, 분할 정복
// 
// 가장 핵심은 중위 순회느 루트가 중간에 오는 것이므로 루트를 기준으로 왼쪽 트리, 오른쪽 트리를 나눌 수 있다.
// 따라서, 전위 순회에서 맨 앞은 무조건 루트 노드가 될 것이다.
// 그럼 해당 루트 노드를  찾아 중위 순회에서는 루트 노드의 왼쪽 노드의 크기와 오른쪽 노드의 크기를 알 수 있다.
// 그럼 윈쪽 노드에서는 다시 루트 노드가 존재할 것이고 해당 루트 노드에 대한 왼쪽 노드와 오른쪽 노드로 또 나뉜다.
// 해당 과정을 반복하여 후위 순회에 맞게 출력하면 종료
// 후위 순회는 왼쪽 -> 오른쪽 -> 루트 노드 순으로 순회하므로 왼쪽 트리를 먼저 재귀로 만들고 다음 오른쪽 노드, 마지막으로 아무것도 없다면 출력하면 된다.

// 핵심이 되는 중위 순회에서 루트 노드가 중앙에 있다는 점과 양쪽의 트리 (왼쪽, 오른쪽 트리)를 나누어 재귀를 진행하여 출력하게 된다면 풀 수 있었던 문제

// 실행시간 : 68ms