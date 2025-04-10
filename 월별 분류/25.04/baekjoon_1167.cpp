#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int node;
	int value;
};

int N;
vector<Node> v[100001];
long long ans = 0;

int end_node = 0;


void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int node, next, value;
		cin >> node;
		while (1) {
			cin >> next;
			if (next == -1) break;

			cin >> value;
			v[node].push_back({ next, value });
		}
	}

}

void BFS(int start_node) {

	queue<Node> q;
	int check[100001] = { 0, };
	q.push({ start_node, 0});
	check[start_node] = 1;

	while (!q.empty()) {

		int now = q.front().node;
		int now_val = q.front().value;
		q.pop();

		if (now_val > ans) {
			end_node = now;
			ans = now_val;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].node;
			if (check[next] == 1) continue;
			 
			int next_val = v[now][i].value + now_val;
			check[next] = 1;
			q.push({ next, next_val });
		}
	}

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	BFS(1);
	BFS(end_node);
	cout << ans;

	return 0;
}

// 백준 1167 : 트리의 지름
// 트리, BFS(깊이 우선 탐색)

// 이 문제는 트리의 지름을 구하는 문제로 트리의 지름은 임의의 두 노드의 거리가 가장 길 때, 해당 거리를 트리의 지름이라고 한다.

// 해당 문제의 가장 핵심은 BFS를 구하는 횟수이다.
// 문제에서 주어지는 것은 모든 노드와 연결된 다른 노드, 거리이다.
// 트리의 모양을 사전에 주어진 것이 아닌 그냥 길이 이어지고 해당 길의 비용이 있는 다익스트라와 거의 유사하게 조건을 제공한다.
// 따라서, 루트 노드를 찾는 것은 매우 어려워 어디서 시작해야 트리의 지름을 구할 수 있을 지 헷갈리는 경우가 발생한다.

// 핵심은 임의의 노드에서 시작하고 BFS를 2번 하는 것이다.
// 왜 2번 하는가?
// 내가 임의의 노드를 선택했다고 가정해보자. 해당 노드에서 가장 거리가 먼 점을 구해보면 결국 트리 전체에서 봤을 때 트리의 가장 끝이 될 것이다.
// 그럼 해당 지점에서 가장 거리가 먼 곳을 고르면 가장 거리가 긴 트리의 지름을 구할 수 있는 것이다.

// 트리의 루트가 정해지지 않았을 때 어떻게 해결하면 좋을지 아이디어를 얻는 것이 중요했던 문제

// 실행 시간 : 76ms ~ 212ms