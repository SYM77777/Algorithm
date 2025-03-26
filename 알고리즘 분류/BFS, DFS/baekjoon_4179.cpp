#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
int man_y = 0;
int man_x = 0;
int ans_turn = -1;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int maze[1001][1001];
int check[1001][1001];
int check_turn[2001];

struct burn {
	int y;
	int x;
};

deque<burn> Fire;


struct Edge {
	int y;
	int x;
	int turn;
	bool operator<(Edge right) const {
		return turn > right.turn;
	}
};

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < C; j++) {
			if (a[j] == 'J') {
				man_y = i;
				man_x = j;
			}
			else if (a[j] == 'F') {
				Fire.push_back({ i, j });
				maze[i][j] = 2;
			}
			else if (a[j] == '#') {
				maze[i][j] = 1;
			}
			else {
				maze[i][j] = 0;
			}
		}
	}
}
void cal() {

	queue<Edge> q;
	q.push({ man_y, man_x, 0 }); 
	check[man_y][man_x] = 1;

	while (!q.empty()) {

		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_turn = q.front().turn;
		int next_turn = now_turn + 1;
		q.pop();

		if (now_y == 0 || now_x == 0 || now_y == R - 1 || now_x == C - 1) {
			ans_turn = next_turn;
			break;
		}

		if (check_turn[now_turn] != 1) {
			check_turn[now_turn] = 1;
			int a = Fire.size();
			for (int i = 0; i < a; i++) {
				int now_fire_y = Fire.front().y;
				int now_fire_x = Fire.front().x;
				Fire.pop_front();

				for (int i = 0; i < 4; i++) {
					int next_fire_y = now_fire_y + dy[i];
					int next_fire_x = now_fire_x + dx[i];

					if (next_fire_y < 0 || next_fire_x < 0 || next_fire_y >= R || next_fire_x >= C) continue;
					if (maze[next_fire_y][next_fire_x] == 1 || maze[next_fire_y][next_fire_x] == 2) continue;

					maze[next_fire_y][next_fire_x] = 2;
					Fire.push_back({ next_fire_y, next_fire_x });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + dy[i];
			int next_x = now_x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= R || next_x >= C) continue;
			if (check[next_y][next_x] == 1 || maze[next_y][next_x] == 1 || maze[next_y][next_x] == 2) continue;

			check[next_y][next_x] = 1;
			q.push({ next_y, next_x, next_turn });
		}



	}

	if (ans_turn == -1) cout << "IMPOSSIBLE\n";
	else cout << ans_turn << "\n";


}

int main() {

	input();
	cal();

	return 0;
}

// 백준 4179번 : 불!
// BFS, 그래프 탐색

// 해당 문제는 불이 발생한 지점과 현재 위치를 주어지고 탈출 할 수 있는지 여부를 확인하는 문제이다.

// 풀이방법
// 1. 불을 먼저 움직인다.
// 2. 사람을 움직인다. 단, 불이 없는지 / 벽이 없는지 / 이미 방문한 지역이 아닌지 를 확인한다.
// 3. 현재 이동한 지역이 벽의 끝이라면 탈출한다.

// 해당 문제에서 BFS 구현 자체는 어렵지 않다. 
// 그러나 시간 제한 1초와 메모리 제한 256MB가 과제였던 문제
// 맵의 가로, 세로 크기 R, C가 1000으로 제한되어 있었고 불을 움직이는 과정과 사람을 움직이는 과정 모두 BFS 반복문으로 움직였기 때문에 시간제한이 걸릴 것으로 처음엔 생각되었다.
// 하지만, 막상 실행시켜보니 60ms 정도로 매우 빠르게 실행되었다.
// 처음 제출 했을 때는, 메모리 초과가 발생하여 해당 오류를 찾는데 시간이 조금 걸렸는데 원인은 불을 번지게 하는 과정에서 이미 불이 번진곳도 계속 queue에 들어가는 에러가 발생하였다.
// 따라서, 해당 경계조건을 추가적으로 설정하여 메모리 문제를 해결하여 문제를 풀 수 있었다.

// R, C가 1000 정도의 BFS는 충분히 1초내로 탐색 가능하다.
// 다만, 256MB의 메모리는 매우 적기 때문에 메모리 초과가 나올 수 있으니 queue에 넣을 데이터의 경계 조건을 잘 설정해주는 것이 중요하다!

// 각 구성 요소별 대략적인 메모리 사용량 추정 (최악의 경우 기준)

// 1. maze[1001][1001]: int형
//    크기: 1001 × 1001 × 4 bytes = 4MB

// 2. check[1001][1001]: int형
//    크기: 1001 × 1001 × 4 bytes = 4MB

// 3. check_turn[2001]: int형
//    크기: 2001 × 4 bytes = 8KB (무시 가능 수준)

// 4. queue<Edge> (지훈이의 이동 큐)
//    Edge 구조체는 int y, x, turn -> 12 bytes
//    최악의 경우 모든 칸(1000×1000)에 대해 한 번씩 들어간다고 하면:
//    약 1,000,000 × 12 bytes = 약 12MB

// 5. deque<burn> Fire
//    burn 구조체는 int y, x -> 8 bytes
//    모든 칸이 불로 번진다고 하면:
//    1,000,000 × 8 bytes = 약 8MB

//  총합: 약 28MB 정도
//  (메모리 제한 256MB 기준으로는 충분히 여유 있음)


// 실행시간 : 60ms