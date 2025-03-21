#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;
int arr[1001][1001] = { 0, };
int min_data_0[11][1001][1001] = { 0, };
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int ans = -1;

struct ABC {
	int y;
	int x;
	int check = 0;
	int cnt;
	int day_night; // 밤 : 1, 낮 : 0
};

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;

		/*long long b = pow(10, M - 1);*/           // pow는 double을 반환하기 떄문에 문제가 발생할 수 있습니다. (pow는 cmath 라이브러리)
		// 또한 long long 의 최대 범위는 10의 18제곱승 정도이기 떄문에 1000도 문제가 발생할 수 있다.
		// 따라서 이를 해결하기 위해서는 문자열로 받은 다음 하나씩 해결해야 된다고 생각된다.

		for (int j = 0; j < a.length(); j++) arr[i][j] = (int)(a[j] - '0');


	}

}

void cal() {

	queue<ABC> q;
	q.push({0, 0, 0, 1, 0});
	min_data_0[0][0][0] = 0;

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_check = q.front().check;
		int now_cnt = q.front().cnt;
		int now_day = q.front().day_night;
		q.pop();

		if (now_y == N-1 && now_x == M-1) {
			if (ans == -1) ans = now_cnt;
			else if (ans != -1 && ans > now_cnt) ans = now_cnt;
			else continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now_y + dy[i];
			int nx = now_x + dx[i];
			int n_check = now_check;
			int n_cnt = now_cnt + 1;
			int n_day = now_day;

			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;

			if (arr[ny][nx] == 1 && n_check == K) continue;
			else if (arr[ny][nx] == 1 && n_check < K) { // 벽 뚫고 이동
				if (n_day == 1) {
					n_day += 1;
					n_cnt += 1;
				}
				n_check += 1;
				if (min_data_0[n_check][ny][nx] != 0 && min_data_0[n_check][ny][nx] > n_cnt) min_data_0[n_check][ny][nx] = n_cnt;
				else if (min_data_0[n_check][ny][nx] == 0) min_data_0[n_check][ny][nx] = n_cnt;
				else continue;
			}
			else {
				if (min_data_0[n_check][ny][nx] != 0 && min_data_0[n_check][ny][nx] > n_cnt) min_data_0[n_check][ny][nx] = n_cnt;
				else if (min_data_0[n_check][ny][nx] == 0) min_data_0[n_check][ny][nx] = n_cnt;
				else continue;
			}

			n_day = (n_day + 1) % 2;

			q.push({ ny, nx, n_check, n_cnt, n_day });
		}

	}
}


int main() {

	input();
	cal();

	cout << ans;

	return 0;
}

// 벽부수고 이동하기 3
// 백준 2206의 응용 문제
// 해당 문제는 벽을 부수고 이동할 수 있는 맵이 주어지고 목적지인 (N, M)까지의 최단거리를 구하는 BFS 문제이다.
// 해당 문제를 해결하기 위해서는 가장 중요한 조건 몇가지가 필수적이다.
// 일반적으로 주어지는 map의 형태와 달리 띄어쓰기가 존재하지 않아 해당 요소들을 받는 경우 최대 1000의 자리 숫자까지 존재하게 된다.
// 따라서, 이는 int, double, long으로 자료형을 선언할 시 문제가 발생할 수 있다.
// 이를 해결하기 위해서 입력을 받을 때 string 문자열 형태로 받아 이를 정수형으로 변환하여 입력받도록 설계하였다.
// 그 이후는 단순한 bfs 문제로 해결하였습니다.
// 제곱승을 나타내기 위한 pow 도 double로 문제가 발생할 수 있습니다.


// 이전 문제와 다른점은 벽을 1번 부술 수 있다고 제한을 걸던 제약 조건이 최대 10번까지 부술 수 있는 것으로 변경되었습니다.
// 따라서, 이를 해결하기 위해서 배열의 형태를 3차원 배열로 변경하여 벽을 부순 횟수에 따라 다르게 저장할 수 있도록 확인 코드를 변경하였습니다.

// 추가로 벽부수고 이동하기 3에서는 낮과 밤이 추가되어 벽이 부수는 것은 낮에만 동작하도록 구현해야 한다.
// 따라서, 낮과 밤 코드를 추가하고 이에 따라 3차원 배열에 이동하도록 구현
// 벽을 만난 시점이 밤인 경우 : 벽을 부수기 위해서는 한번 멈추고 나아가야 한다. 따라서, 해당 지역의 소요된 시간을 + 1을 더해주고 진행.
// 벽을 만난 시점이 낮인 경우 : 1, 2 문제와 동일하게 구현

// 실행시간 약 1200ms (1.2초)

// 더 빠른 실행을 한 코드를 아래에 예시 코드를 아래에 남긴다.
// 실행시간 약 256ms (0.25초)
// 위 코드와 다른 점은 최소값을 기억하는 부분에서 남은 벽부수기 횟수를 전체에서 1씩 감소시키는 방향으로 구현하였습니다.


// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// struct POS {
//     int r, c, k;
// };

// char map[1000][1000];
// int visit[1000][1000];

// const int dr[4] = {-1, 0, 1, 0};
// const int dc[4] = {0, 1, 0, -1};

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int N, M, K, dist = 0;
//     cin >> N >> M >> K;
//     for (int r = 0; r < N; r++) {
//         for (int c = 0; c < M; c++) {
//             cin >> map[r][c];
//             visit[r][c] = -1;
//         }
//     }
//     visit[0][0] = K;

//     bool day = 0;
//     queue<POS> q;
//     q.push(POS{0, 0, K});
//     while (!q.empty()) {
//         day = !day;
//         dist++;

//         int size = q.size();
//         for (int i = 0; i < size; i++) {
//             POS cur = q.front(); q.pop();

//             if (cur.r == N - 1 && cur.c == M - 1) {
//                 cout << dist;
//                 return 0;
//             }

//             if (cur.k != visit[cur.r][cur.c]) continue;

//             for (int d = 0; d < 4; d++) {
//                 int nr = cur.r + dr[d];
//                 int nc = cur.c + dc[d];

//                 if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

//                 if (map[nr][nc] == '0') {
//                     if (visit[nr][nc] >= cur.k) continue;

//                     visit[nr][nc] = cur.k;
//                     q.push(POS{nr, nc, cur.k});
//                 } else if (cur.k > 0) {
//                     if (visit[nr][nc] >= cur.k - 1) continue;

//                     if (day) {
//                         visit[nr][nc] = cur.k - 1;
//                         q.push(POS{nr, nc, cur.k - 1});
//                     } else {
//                         q.push(POS{cur.r, cur.c, cur.k});
//                     }
//                 }
//             }
//         }
//     }

//     cout << "-1";
//     return 0;
// }