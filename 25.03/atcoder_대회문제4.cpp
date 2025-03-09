#include <iostream>
#include <vector>

using namespace std;

struct ABC {
	int u;
	int v;
	unsigned long long w;
};

vector<ABC> v;
int N, M;
unsigned long long ans = (1LL << 60);
int check[10][10]; // 이미 거쳐간 노드인가?
int visited[10][10];
int visited2[10];

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int U, V;
		unsigned long long W;
		cin >> U >> V >> W;
		v.push_back({ U, V, W });
	}

}


void DFS(int start, int end, unsigned long long now_xor) {

	if (end == N) {

		if (now_xor < ans) ans = now_xor;
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		int n_start = v[i].u; // 다음 시작점
		int n_end = v[i].v; // 다음 종료점
		unsigned long long n_w = v[i].w; // 다음 가중치

		if (n_start != end && n_end != end) continue; // 만약 현재 종료점과 다음 시작점이 다르다. 그럼 패스
		else if (n_start == start && n_end == end) continue;
		else if (n_start == end && n_end == start) continue;
		else if (visited[n_start][n_end] == 1) continue;
		else if (n_end == end && n_start != start && visited2[n_start] == 0) { // 둘이 뒤바뀌어 있으면 바꿔줌
			n_start = v[i].v;
			n_end = v[i].u;
		}
		if (visited2[n_end] == 1) continue;
		unsigned long long tmp = n_w ^ now_xor;
		visited[n_start][n_end] = 1;
		visited2[n_end] = 1;
		DFS(n_start, n_end, tmp);
		visited[n_start][n_end] = 0;
		visited2[n_end] = 0;
	}



}

void clean() {
	for (int i = 0; i < N; i++) {
		visited2[i] = 0;
		for (int j = 0; j < N; j++) visited[i][j] = 0;
	}
}


int main() {

	input();
	for (int i = 0; i < v.size(); i++) {
		if (check[v[i].u][v[i].v] == 0 && v[i].u == 1) {
			clean();
			check[v[i].u][v[i].v] = 1;
			visited[v[i].u][v[i].v] = 1;
			visited2[v[i].u] = 1;
			visited2[v[i].v] = 1;
			DFS(v[i].u, v[i].v, v[i].w);
		}
		else if (check[v[i].v][v[i].u] == 0 && v[i].v == 1) {
			clean();
			check[v[i].v][v[i].u] = 1;
			visited[v[i].v][v[i].u] = 1;
			visited2[v[i].u] = 1;
			visited2[v[i].v] = 1;
			DFS(v[i].v, v[i].u, v[i].w);
		}
		else continue;

	}

	cout << ans << "\n";

	return 0;
}


// 해당 문제는 노드 개수와 간선, 가중치를 주어주고 가중치의 xor값이 제일 작은 값을 찾는 문제이다.
// 주어진 조건으로 N과 M의 최대가 10개와 45개로 고정되어있다.
// 따라서, 해당 문제는 DFS로 풀어도 넉넉히 풀 수 있다.

// 실행시간 9ms