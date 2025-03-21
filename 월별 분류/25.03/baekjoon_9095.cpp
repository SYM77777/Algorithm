#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T;


void input() {
	cin >> T;
}

void cal() {

	int ans = 0;
	int num;
	int arr[12] = { 0, };
	cin >> num;

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 3; i++) {
			int tmp = now + i;
			if (tmp > num) continue;
			else if (tmp == num) arr[tmp]++;
			else {
				arr[tmp]++;
				q.push(tmp);
			}
			

		}
	}

	ans = arr[num];

	cout << ans << "\n";

}


int main() {
	input();
	for (int i = 0; i < T; i++) cal();
}

// DP 문제
// 1, 2, 3 더하기
// 1, 2, 3 더하기로 입력받은 정수를 나타낼 수 있는 방법을 전부 세는 문제이다.
// 예를 들어 4는 1 + 1 + 1 + 1, 3 + 1, 1 + 3, 등 7가지가 존재한다.
// 순서가 필요한 문제이므로 처음 1, 2, 3을 queue에 입력받은 상태로 시작
// 처음 1에서 시작하면 다음으로 올 수 있는 숫자는 2, 3, 4 (1 + 1 / 1 + 2 / 1 + 3)이다. 시작점이 1만 존재하는 것이 아닌 2, 3도 있으므로 1, 2, 3 모두 queue에 입력해줘야 한다.
// 따라서 목표 지점보다 다음 오는 수가 작으면 해당 수를 다시 queue에 입력하고 만약 같거나 넘어가면 다시 넣지 않는 작업 실행

// 실행시간 : 0ms