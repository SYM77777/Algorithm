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
};

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;

		/*long long b = pow(10, M - 1);*/           // pow는 double을 반환하기 떄문에 문제가 발생할 수 있습니다. (pow는 cmath 라이브러리)
		// 또한 long long 의 최대 범위는 10의 18제곱승 정도이기 떄문에 1000도 문제가 발생할 수 있다.
		// 따라서 이를 해결하기 위해서는 문자열로 받은 다음 하나씩 해결해야 된다고 생각된다.

		for (int j = 0; j < a.length(); j++) {
			arr[i][j] = (int)(a[j] - '0');
		}


	}

}

void cal() {

	queue<ABC> q;
	q.push({0, 0, 0, 1});
	min_data_0[0][0][0] = 0;

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_check = q.front().check;
		int now_cnt = q.front().cnt;
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

			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;

			if (arr[ny][nx] == 1 && n_check == K) continue;
			else if (arr[ny][nx] == 1 && n_check < K) {
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

			q.push({ ny, nx, n_check, n_cnt });
		}

	}
}


int main() {

	input();
	cal();

	cout << ans;

	return 0;
}

// 백준 2206의 응용 문제
// 벽부수고 이동하기
// 해당 문제는 벽을 부수고 이동할 수 있는 맵이 주어지고 목적지인 (N, M)까지의 최단거리를 구하는 BFS 문제이다.
// 해당 문제를 해결하기 위해서는 가장 중요한 조건 몇가지가 필수적이다.
// 일반적으로 주어지는 map의 형태와 달리 띄어쓰기가 존재하지 않아 해당 요소들을 받는 경우 최대 1000의 자리 숫자까지 존재하게 된다.
// 따라서, 이는 int, double, long으로 자료형을 선언할 시 문제가 발생할 수 있다.
// 이를 해결하기 위해서 입력을 받을 때 string 문자열 형태로 받아 이를 정수형으로 변환하여 입력받도록 설계하였다.
// 그 이후는 단순한 bfs 문제로 해결하였습니다.
// 제곱승을 나타내기 위한 pow 도 double로 문제가 발생할 수 있습니다.


// 이전 문제와 다른점은 벽을 1번 부술 수 있다고 제한을 걸던 제약 조건이 최대 10번까지 부술 수 있는 것으로 변경되었습니다.
// 따라서, 이를 해결하기 위해서 배열의 형태를 3차원 배열로 변경하여 벽을 부순 횟수에 따라 다르게 저장할 수 있도록 확인 코드를 변경하였습니다.

// 실행시간 476ms (0.476초)