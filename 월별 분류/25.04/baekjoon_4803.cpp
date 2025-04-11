#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isTree(int start, vector<int> Tree[], int check[]) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	check[start] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int parent = q.front().second;
		q.pop();

		for (int next : Tree[cur]) {
			if (next == parent) continue;
			if (check[next]) return false;
			check[next] = 1;
			q.push({ next, cur });
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int caseNum = 1;
	while (1) {
		vector<int> Tree[501];
		int check[501] = { 0, };

		int N, M, ans = 0;
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 0; i < M; i++) {
			int node1, node2;
			cin >> node1 >> node2;
			Tree[node1].push_back(node2);
			Tree[node2].push_back(node1);
		}

		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				if (isTree(i, Tree, check)) ans++;
			}
		}

		cout << "Case " << caseNum << ": ";
		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";

		caseNum++;
	}

	return 0;
}


// 백준 4803 : 트리
// 트리, BFS

// 해당 문제는 주어진 노드의 쌍이 간선으로 연결되어 있을 떄 트리를 몇개 이루고 있는지 수를 구하는 문제이다.
// 
// 여기서 핵심은 원형으로 이루어져 있다면 트리가 구성되어 있지 않다는 것이다.
// 또한, 요소 하나만 있다면 그 또한 하나의 트리로 구성되어 있다는 것이다.

// 실행시간 : 28ms