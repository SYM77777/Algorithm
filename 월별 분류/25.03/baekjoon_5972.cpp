#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
	int num;
	int cost;
	bool operator<(Edge right) const {
		return cost > right.cost;
	}
};

int N, M;
vector<Edge> alis[50002];


void input() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int start, end, exp;
		cin >> start >> end >> exp;
		alis[start].push_back({ end, exp });
		alis[end].push_back({ start, exp });
	}

}

void dijk(int node) {

	// 1. pq 준비
	priority_queue<Edge> pq;

	// 2. 정답 배열 생성
	int dist[50002];
	for (int i = 0; i <= N; i++) {
		dist[i] = 1e9;
	}

	// 2-2. 시작 노드 생성
	dist[node] = 0;

	pq.push({ node, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		for (int i = 0; i < alis[now.num].size(); i++) {
			Edge next = alis[now.num][i];
			int next_cost = next.cost + dist[now.num];

			if (dist[next.num] <= next_cost) continue;

			pq.push({ next.num, next_cost });
			dist[next.num] = next_cost;

		}
	}


	cout << dist[N] << "\n";


}


int main() {

	input();
	dijk(1);


	return 0;
}


// 백준 5972번 : 택배 배송
// 가장 기본적인 다익스트라를 물어보는 문제이다.
// 다익스트라란?
// 다익스트라(Dijkstra) 알고리즘은 그래프에서 한 정점에서 다른 모든 정점까지의 최단 경로를 구하는 알고리즘이다.
// 가중치가 있는 그래프에서 가중치가 음수가 아닐대 한 정점에서 다른 모든 정점까지의 최단 거리를 구하고 싶을 때 자주 사용하는 알고리즘이다.
// 특히, 특정 도시에서 다른 모든 도시까지 가장 빠르게 가는 방법을 알고 싶다면 다익스트라를 사용한다.

// 핵심 코드는 2가지라고 생각한다.

// 우선 priority queue 이다. 
// 다익스트라는 가중치가 가장 작은 정점을 먼저 탐색해야 하는데, 이걸 효율적으로 처리하기 위해서 priority_queue를 쓰면 O(log N) 시간 안에 가장 작은 값을 꺼낼 수 있다.
// -- 일반 배열이나 큐로 구현하면 매번 최소값을 찾아야 해서 O(N)이 소요. 
// 또한, bool operator<(Edge right) const { return cost > right.cost } 해당 코드를 활용해야 우선순위 큐가 cost 값이 적은 기준으로 우선순위가 잡히게 된다. 따라서, 더 빠른 탐색이 가능

// 다음 BFS를 적용하여 해당 노드와 이어진 다른 노드를 탐색하고 가장 만약 연결된 노드로 이동하였을때 비용이 더 작다면 이동하여 다시 pq에 대입하고 아니라면 계속 진행하여 끝까지 진행한다.

// 마지막으로 dist 값을 초기화하는 것을 주의하자.

// 실행시간 : 64ms