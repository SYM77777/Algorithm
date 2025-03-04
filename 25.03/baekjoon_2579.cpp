#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[301] = { 0, };
int dp[301] = { 0, };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
}

void cal() {

	dp[0] = map[0];
	dp[1] = map[0] + map[1];
	dp[2] = max(map[0] + map[2], map[1] + map[2]);

	for (int i = 3; i < N; i++) {
		int a = dp[i - 2] + map[i];
		int b = dp[i - 3] + map[i - 1] + map[i];
		if (a > b) dp[i] = a;
		else dp[i] = b;
	}

	cout << dp[N - 1] << "\n";
}


int main() {

	input();
	cal();
	return 0;
}


// dp문제
// 계단오르기
// 계단을 올라 제일 끝에 도착했을때 얻을 수 있는 제일 큰 수를 얻는 문제이다.
// 제약 조건으로는 연속된 3개의 계단을 오를수 없고 한번에 갈 수 있는 계단 수는 2칸이다. 따라서 3번째 칸을 가더라도 1, 2, 3을 모두 거치는 것은 불가능
// 이를 고려하여 한번 갈 수 있는 모든 경우의 수를 5까지만 생각해보자.
// 1번째 칸 : 1
// 2번째 칸 : 1 + 1 / 2
// 3번째 칸 : 1 + 2 / 2 + 1
// 4번째 칸 : 1 + 1 + 2 / 1 + 2 + 1 / 2 + 2  ---> 1-2-4 / 1-3-4 / 2-4(제외) : 4번째 칸을 가는 최대값은 2-4가 아닌 1-2-4이므로 무조건적으로 1-2-4가 됨됨
// 5번째 칸 : 1 + 1 + 2 + 1 / 1 + 2 + 2 / 1 + 2 + 1 + 1 ---> 2-4-5 / 3-5
// 무언가 보이는가? 1, 2, 3은 갈 수 있는 방식이 고정된다. 
// 4 이후로는 규칙성을 보이는데 4이상의 수를 임의로 N이라 하면 N-2 칸의 최대값 + 2 와 N - 1칸의 최대값값 + 1 이렇게 나타내어 진다.
// 이를 점화식으로 나타내면 dp[N] = dp[N - 2] + map[N] / dp[N] = dp[N - 3] + map[N - 1] + map[N] 중 큰 값을 고르는 것이다.

// dq의 예시를 볼 수 있던 아주 기본적인 문제라고 생각된다.
// 실행시간 : 0ms