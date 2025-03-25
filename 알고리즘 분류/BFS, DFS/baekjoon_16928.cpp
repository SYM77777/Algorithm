#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int check[101] = { 0, };
vector<int> ladder[101];
vector<int> snake[101];

struct Data {
	int turn;
	int place;
};

int player_y = 0;
int player_x = 0;

void input() {
	cin >> N >> M;
	for (int i = 1; i < 101; i++) {
		check[i] = 101;
	}

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x].push_back(y);
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		snake[x].push_back(y);
	}

	
}

void cal() {

	queue<Data> q;
	q.push({0, 1});

	while (!q.empty()) {

		int now_turn = q.front().turn;
		int now_place = q.front().place;
		q.pop();

		if (now_place == 100) continue;

		for (int i = 1; i <= 6; i++) {

			int next_place = now_place + i;
			int next_turn = now_turn + 1;


			if (next_place >= 101 || check[next_place] <= next_turn) continue;

			if (ladder[next_place].size() != 0 && ladder[next_place].front() != -1) {
				int move_place = ladder[next_place].front();
				if (check[move_place] > next_turn) {
					check[move_place] = next_turn;
					q.push({ next_turn, move_place });
				}
			}
			else if (snake[next_place].size() != 0 && snake[next_place].front() != -1) {
				int move_place = snake[next_place].front();
				if (check[move_place] > next_turn) {
					check[move_place] = next_turn;
					q.push({ next_turn, move_place });
				}
			}
			else {
				check[next_place] = next_turn;
				q.push({ next_turn, next_place });
			}

		}
	}




}

int main() {

	input();
	cal();

	cout << check[100] << "\n";

	return 0;
}

// 백준 16928번 : 뱀과 사다리게임
// 그래프 분류, 그래프 탐색, BFS
// 해당 문제는 주사위를 1~6까지 본인이 선택할 수 있을 때 1에서 100까지 가는데 몇번의 횟수로 갈 수 있는지 확인하는 문제이다.
// 추가적으로, 사다리와 뱀이라는 요소가 존재하여 사다리나 뱀의 시작칸에 도작하면 무조건적으로 이동해야하는 것이다.

// 해당 문제는 이차원 배열도 아닌 일차원 배열로 100까지만 가면 종료된다. 만약 최악의 경우의 수로 뱀과 사다리가 하나도 없다고 한다면 1~6 주사위로만 100까지 간다면 O(1)이다.
// 따라서, 시간 초과의 문제는 발생하지 않는다.

// 처음에 경계조건 설정과 무조건적으로 이동한다는 것을 고려하지 않아 답에 영향을 주어 한번 틀리게 제출하였다.
// 항상 문제 조건을 정확하게 지키는 연습을 하도록 하자.

// 실행시간 : 0ms