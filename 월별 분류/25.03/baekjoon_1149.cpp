#include <iostream>
#include <algorithm>

using namespace std;

int N;
int R, G, B;
int RGB[1001][3];
int dp[1001][3];
int ans = 0;

void input() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}


}

void cal() {

	dp[0][0] = RGB[0][0];
	dp[0][1] = RGB[0][1];
	dp[0][2] = RGB[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = RGB[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = RGB[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = RGB[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])) << "\n";

}

int main() {

	input();
	cal();

	return 0;
}

// 백준 1149 : RGB 거리
// 해당 문제의 핵심은 DP 문제의 핵심과도 연결되는 것인데  "이전의 최소값을 불러와서 더해준다" 이다.
// 현재를 선택할 때 항상 "이전 단계에서 최소한의 비용을 들인 경우"를 기반으로 생각해 보면 한층 더 쉽게 해결될 것이다.
// 처음에는 앞으로 선택할때 2개 이후의 값을 보고 선택해야 하나? 이렇게 생각해서 허덕이던 문제

// RGB 3가지 선택지를 처음 시작하여 다음에 1번 지점에서 선택할 때는 이전의 2, 3중 최소값을 선택하는 방식으로 N 까지 나아가면 되던 문제이다.

// 실행시간 : 0ms