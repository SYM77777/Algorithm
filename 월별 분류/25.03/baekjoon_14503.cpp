#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int r, c, d;
int arr[52][52] = { 0, };
int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1 };
int ans = 0;

struct Data {
	int y;
	int x;
	int dir;
};


void input() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N + 1; i++) {
		arr[i][0] = 1;
		arr[i][M + 1] = 1;
	}

	for (int i = 0; i < M + 1; i++) {
		arr[0][i] = 1;
		arr[N + 1][i] = 1;
	}
}

void BFS() {

	queue<Data> q;
	q.push({ r + 1, c + 1, d });

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_dir = q.front().dir;
		bool check = true;
		q.pop();

		if (arr[now_y][now_x] == 0) {
			arr[now_y][now_x] = 2;
			ans++;
		}

		for (int i = 0; i < 4; i++) {
			int next_dir = (now_dir + (3 - i)) % 4;
			int next_y = now_y + dy[next_dir];
			int next_x = now_x + dx[next_dir];

			if (arr[next_y][next_x] == 0) {
				q.push({ next_y, next_x, next_dir });
				check = false;
				break;
			}
		}

		if (check) {
			int next_dir = (now_dir + 2) % 4;
			int next_y = now_y + dy[next_dir];
			int next_x = now_x + dx[next_dir];

			if (arr[next_y][next_x] != 1) {
				q.push({ next_y, next_x, now_dir });
				continue;
			}
		}
		else continue;


	}

}

int main() {


	input();
	BFS();
	cout << ans;


	return 0;
}

// 14503 : 로봇청소기
// 완전 탐색 문제
// DFS, BFS
// 해당 문제는 BFS로 쉽게 풀리는 완전탐색 문제이다.
// 더 메모리를 짧게 쓰는 코드를 확인해본 결과, DFS를 사용하였다.
// N, M의 최대값이 50으로 주어졌기 때문에 DFS를 사용해도 무방했던 문제라고 생각한다

// 실행시간 : 0ms
// 메모리 : 2032 KB