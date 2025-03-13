#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int map[101][101]; // 사과 위치
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int ans = 0;

struct Data {
	int X;
	char C;
};

struct snake {
	int y;
	int x;
};

queue<Data> q;
deque<snake> sn;

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int W, L;
		cin >> W >> L;
		map[W - 1][L - 1] = 1;
	}
	int L;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char C;
		cin >> x >> C;
		q.push({ x, C });
		
	}
}

void cal() {

	int now_dir_y = 0;
	int now_dir_x = 0;
	int now_dir = 0;
	int cnt = 0;
	bool check = false;

	sn.push_back({ now_dir_y, now_dir_x });
	int snake_dir[101][101] = { 0, };
	snake_dir[0][0] = 1;

	while (!q.empty()) {
		int n_time = q.front().X;
		char n_turn = q.front().C;
		q.pop();
		
		for (int i = cnt; i < n_time; i++) {
			int snake_y = sn.front().y;
			int snake_x = sn.front().x;
			int snake_back_y = sn.back().y;
			int snake_back_x = sn.back().x;
			
			// 다음 머리가 갈 곳
			int ny = snake_y + dy[now_dir];
			int nx = snake_x + dx[now_dir];

			if (ny >= N || nx >= N || ny < 0 || nx < 0) {
				ans++;
				check = true;
				break;
			}

			if (snake_dir[ny][nx] == 1) { // 움직이려는 머리가 이미 몸에 위치하는 곳이다. 그럼 종료
				ans++;
				check = true;
				break;
			}

			if (map[ny][nx] == 1) { // 사과를 먹음
				map[ny][nx] = 0; // 사과는 없어지고 꼬리는 그대로
			}
			else {
				snake_dir[snake_back_y][snake_back_x] = 0; // 사과가 없으면 뱀 전체가 움직임
				sn.pop_back();
			}

			

			snake_dir[ny][nx] = 1;
			sn.push_front({ ny, nx });
			ans++;

		}

		if (check) break;

		cnt = n_time;
		if (n_turn == 'D') now_dir = (now_dir + 1) % 4;
		else if (n_turn == 'L') now_dir = (now_dir + 3) % 4;

	}


	if (check) cout << ans << "\n";
	else {

		while (!check) {
			int snake_y = sn.front().y;
			int snake_x = sn.front().x;
			int snake_back_y = sn.back().y;
			int snake_back_x = sn.back().x;

			int ny = snake_y + dy[now_dir];
			int nx = snake_x + dx[now_dir];

			if (ny >= N || nx >= N || ny < 0 || nx < 0) {
				ans++;
				check = true;
				break;
			}

			if (snake_dir[ny][nx] == 1) {
				ans++;
				check = true;
				break;
			}

			if (map[ny][nx] == 1) {
				map[ny][nx] = 0;
			}
			else {
				snake_dir[snake_back_y][snake_back_x] = 0;
				sn.pop_back();
			}

			

			snake_dir[ny][nx] = 1;
			sn.push_front({ ny, nx });
			ans++;

		}

		cout << ans << "\n";
	}
}

int main() {

	input();
	cal();


	return 0;
}

// 뱀 : BFS
// 뱀이 기어다니며 사과를 먹으면 몸이 늘어나고 그렇지 않으면 늘어나지 않은 상태로 진행하는 문제
// 해당 문제는 기본적인 BFS와 check를 어떻게 할지에 대한 고민을 조금 하면 풀리던 문제엿다.

// 실행시간 : 0ms