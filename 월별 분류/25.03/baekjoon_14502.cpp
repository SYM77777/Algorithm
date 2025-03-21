#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[9][9] = { 0, };

int ans = 0;

struct Data {
	int y;
	int x;
};


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}


void DFS(int cnt, int map[][9], int start, int end) {

	if (cnt == 3) {
		
		int tmp[9][9] = { 0, };
		queue<Data> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = map[i][j];
				if (map[i][j] == 2) q.push({ i, j });
			}
		}


		while (!q.empty()) {
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();

			if (now_y - 1 >= 0 && tmp[now_y - 1][now_x] == 0) {
				tmp[now_y - 1][now_x] = 2;
				q.push({ now_y - 1, now_x});
			}
			if (now_y + 1 < N && tmp[now_y + 1][now_x] == 0) {
				tmp[now_y + 1][now_x] = 2;
				q.push({ now_y + 1, now_x});
			}
			if (now_x - 1 >= 0 && tmp[now_y][now_x - 1] == 0) {
				tmp[now_y][now_x - 1] = 2;
				q.push({ now_y, now_x - 1 });
			}
			if (now_x + 1 < M && tmp[now_y][now_x + 1] == 0) {
				tmp[now_y][now_x + 1] = 2;
				q.push({ now_y, now_x + 1 });
			}
		}

		int tmp_ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 0) tmp_ans++;
			}
		}

		if (tmp_ans > ans) ans = tmp_ans;

		return;
	}


	for (int i = 0; i < N; i++) {
		if (i < start) continue;
		for (int j = 0; j < M; j++) {
			if (i == start && j < end) continue;
			if (map[i][j] == 0) {
				cnt++;
				map[i][j] = 1;
				DFS(cnt, map, i, j);
				map[i][j] = 0;
				cnt--;
			}
		}
	}

}

int main() {

	input();
	DFS(0, arr, 0, 0);
	cout << ans << "\n";

	return 0;
}

// https://velog.io/@min_gi1123/c-2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EB%A1%9C-%EB%84%98%EA%B8%B0%EA%B8%B0

// 14502번 : 연구소
// 해당 문제는 바이러스가 빈칸으로 계속 퍼지는 데 이를 막기위해 벽을 3개 설치하는 문제이다.
// 해당 문제의 핵심은 배열의 최대값이 8 * 8 배열이라는 것이다. -> 즉, DFS나 BFS와 같은 완전탐색을 사용해도 무방하다.
// 따라서, 벽을 설치할 수 있는 모든 경우의 수를 확인해본 다음 BFS로 바이러스는 퍼트린다. (BFS 혹은 Flood Fill이라고 해도 무방할 것으로 생각된다.)
// BFS로 퍼뜨리고도 남은 안전구역의 개수를 체크하여 가장 많이 남은 경우의 안전구역 수를 체크하고 출력하면 문제 해결

// 실행시간 : 28ms

//#include <stdio.h>
//
//typedef struct {
//	int n, m;
//}DOT;
//
//int Map[10][10], copy[10][10];
//int N, M;
//int Ans = 0;
//int Remain = 0;
//
//int dir[8][2] = { { -1, -1 }, {-1, 0}, {-1,1}, {0,-1}, {0, 1}, {1,-1}, {1,0}, {1,1} };
//
//DOT Q[64];
//int qs, qe, qe_base;
//
//void EnQ(DOT dot) {
//	Q[qe++] = dot;
//}
//
//DOT DeQ() {
//	return Q[qs++];
//}
//
//DOT Move(DOT dot, int d) {
//	int dir[4][2] = { { 0, -1 }, {0, 1}, {-1,0}, {1,0} };
//	dot.n += dir[d][0];
//	dot.m += dir[d][1];
//	return dot;
//}
//
//int Check_Edge(DOT dot) {
//	int dir[8][2] = { { -1, -1 }, {-1, 0}, {-1,1}, {0,-1}, {0, 1}, {1,-1}, {1,0}, {1,1} };
//
//	DOT next;
//	if (Map[dot.n][dot.m] != 0) return 0;
//	for (int d = 0; d < 8; d++) {
//		next.n = dot.n + dir[d][0];
//		next.m = dot.m + dir[d][1];
//		if (Map[next.n][next.m] == 1) return 1;
//	}
//	return 0;
//}
//
//int Check_Meet(DOT dot) {
//	int dir[8][2] = { { -1, -1 }, {-1, 0}, {-1,1}, {0,-1}, {0, 1}, {1,-1}, {1,0}, {1,1} };
//	int ret = 0;
//
//	DOT next;
//	if (Map[dot.n][dot.m] != 0) return 0;
//	for (int d = 0; d < 8; d++) {
//		next.n = dot.n + dir[d][0];
//		next.m = dot.m + dir[d][1];
//		if (Map[next.n][next.m] == 1) ret++;
//		if (ret >= 2) return 1;
//	}
//	return 0;
//}
//
//void Input() {
//	scanf("%d %d", &N, &M);
//	for (int n = 1; n <= N; n++) {
//		for (int m = 1; m <= M; m++) scanf("%d", &Map[n][m]);
//	}
//	for (int n = 0; n <= N + 1; n++) {
//		Map[n][0] = 1;
//		Map[n][M + 1] = 1;
//	}
//	for (int m = 0; m <= M + 1; m++) {
//		Map[0][m] = 1;
//		Map[N + 1][m] = 1;
//	}
//}
//
//void Init() {
//	DOT dot;
//
//	for (int n = 1; n <= N; n++) {
//		for (int m = 1; m <= M; m++) {
//			if (Map[n][m] == 2) {
//				dot.n = n;
//				dot.m = m;
//				EnQ(dot);
//			}
//			if (Map[n][m] == 0) Remain++;
//		}
//	}
//	qe_base = qe;
//	Remain -= 3;
//}
//
//void BFS(DOT dot[3]) {
//	DOT cur, next;
//	int remain = Remain;
//
//	for (int n = 0; n <= N + 1; n++) {
//		for (int m = 0; m <= M + 1; m++) copy[n][m] = Map[n][m];
//	}
//	qe = qe_base;
//	qs = 0;
//
//	while (qs < qe) {
//		cur = DeQ();
//		for (int d = 0; d < 4; d++) {
//			next = Move(cur, d);
//			if (copy[next.n][next.m] == 0) {
//				EnQ(next);
//				copy[next.n][next.m] = 2;
//				remain--;
//				if (remain < Ans) return;
//			}
//		}
//	}
//	if (Ans < remain) Ans = remain;
//}
//
//void BigLoop() {
//	DOT dot[3] = { {1,1}, {1,1}, {1,1} };
//
//	for (int a = 0; a < N * M; a++) {
//		dot[0].n = 1 + a / M;
//		dot[0].m = 1 + a % M;
//		if (Check_Edge(dot[0]) == 0) continue;
//		Map[dot[0].n][dot[0].m] = 1;
//		for (int b = a + 1; b < N * M; b++) {
//			dot[1].n = 1 + b / M;
//			dot[1].m = 1 + b % M;
//			if (Check_Edge(dot[1]) == 0) continue;
//			Map[dot[1].n][dot[1].m] = 1;
//			for (int c = b + 1; c < N * M; c++) {
//				dot[2].n = 1 + c / M;
//				dot[2].m = 1 + c % M;
//				if (Check_Meet(dot[2]) == 0) continue;
//				Map[dot[2].n][dot[2].m] = 1;
//				BFS(dot);
//				Map[dot[2].n][dot[2].m] = 0;
//			}
//			Map[dot[1].n][dot[1].m] = 0;
//		}
//		Map[dot[0].n][dot[0].m] = 0;
//	}
//}
//
//int main() {
//	Input();
//	Init();
//	BigLoop();
//	printf("%d", Ans);
//	return 0;
//}

// 더 최적화된 코드이다.

// 나와는 다른점
// 1. 벽을 주변에 벽이 있는 곳에만 세워 의미없는 빈칸을 배제해 최적화하였다. -> 가장 바깥쪽 테두리 포함
// 2. 맵을 입력할 때 가장 바깥쪽에 벽을 다 둘러 if 와 같은 경계 설정 조건을 굳이 안해도 되도록 설정하였다. -> 최적화의 의미
// 3. 3번째 벽은 앞의 두 벽과 접점이 있는 경우만 고려하여 의미없는 벽이 설치되는 것을 방지하였다고 합니다.