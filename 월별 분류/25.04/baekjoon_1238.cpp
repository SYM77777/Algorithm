#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int node;
	int cost;
	bool operator< (Edge right) const {
		return cost > right.cost;
	}
};

int N, M, X;
vector<Edge> v[1001];
vector<Edge> rev[1001];
int check[1001] = { 0, };
int ans = 0;

void input() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int st, ed, cost;
		cin >> st >> ed >> cost;
		v[st].push_back({ ed, cost });
		rev[ed].push_back({ st, cost });
	}
}

void dijkstra(int node) {
	priority_queue<Edge> pq;
	pq.push({ node, 0 });

	int dist[1001];
	int dist2[1001];
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
		dist2[i] = 1e9;
	}

	dist[node] = 0;
	dist2[node] = 0;

	while (!pq.empty()) {
		int now_node = pq.top().node;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < rev[now_node].size(); i++) {
			int next_node = rev[now_node][i].node;
			int next_cost = rev[now_node][i].cost + now_cost;

			if (next_cost >= dist[next_node]) continue;
			
			dist[next_node] = next_cost;
			pq.push({ next_node, next_cost });
		}

	}

	pq.push({ node, 0 });

	while (!pq.empty()) {
		int now_node = pq.top().node;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v[now_node].size(); i++) {
			int next_node = v[now_node][i].node;
			int next_cost = v[now_node][i].cost + now_cost;

			if (next_cost >= dist2[next_node]) continue;

			dist2[next_node] = next_cost;
			pq.push({ next_node, next_cost });
		}

	}

	for (int i = 1; i <= N; i++) ans = max(ans, (dist[i] + dist2[i]));

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	dijkstra(X);

	cout << ans;

	return 0;
}

// 백준 1238 : 파티
// 다익스트라

// 처음에는 해당 문제를 BFS로 2번 돌려 해결하였다.
// 하지만 잘 생각해보면 가는 길과 오는 길에 결국 X라는 종착지를 갔다가 거기서 출발하는 것이다.
// 다시 말하면 가는 것은 다시 생각해보면 길을 거꾸로 만든다면 종착지에서 출발하게 만들 수 있다는 것이다.

// 해당 경우의 수는 출발지와 목적지를 바꿔 vector에 넣는다면 출발지와 목적지의 노드를 바꿀 수 있고,
// 그 방식으로 X에서 출발하는 것 처럼 만들면 결국 해당 최단값이 특정 i 노드에서 출발했을 때 X까지 도달하는 최단 거리가 될 것이다.
// 그리고 dijkstra를 돌린다면 BFS에서 생기는 모든 출발지에서 X까지의 거리를 전부 for문으로 실행해야 된다는 문제점을 해결할 수  있다.

// 접근법이 매우매우 중요했던 문제

// 실행시간 : 0mx (BFS 실행시 856ms)