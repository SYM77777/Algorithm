#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[501][501];
int dp[501][501] = { 0, };
int ans = 0;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Data {
	int y;
	int x;
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
}

int dfs(int y, int x) {


	if (y == N - 1 && x == M - 1) return 1;

	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (map[ny][nx] < map[y][x]) { // 더 낮은 곳으로만 이동 가능
			dp[y][x] += dfs(ny, nx);
		}
	}

	return dp[y][x];
}

int main() {

	input();
	ans = dfs(0, 0);
	cout << ans << "\n";

	return 0;
}

// DFS + DP(메모이제이션) 방식으로 해결하는 것이 가장 적절하다.
// dp[y][x]를 사용하여 (y, x)에서 도착 지점 까지의 경로 개수를 저장하고 이미 계산된 값이 있으면 다시 탐색하지 않는 방식으로 진행.
// 항상 BFS를 습관적으로 사용하는데 DFS 또한 자주 사용하는 탐색 방법이니 거르지 말고 N, M의 크기가 작다면 사용해보도록 하자.
// 고정관념에 사로잡히지 않는 것이 중요했던 문제


// 실행시간 : 100ms