#include <iostream>
#include <vector>

using namespace std;

int n, k;
long long dp[100001];
vector<int> v;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
}

void cal() {
	dp[0] = 1; // 자기 자신 하나만으로 만들어지는 경우
	for (int j = 0; j < v.size(); j++) {
		int num = v[j];
		for (int i = num; i <= k; i++) {
			dp[i] += dp[i - num];
		}
	}
	
	cout << dp[k] << "\n";

}

int main() {

	input();
	cal();
	return 0;
}

// 1 : 1 : 1
// 2 : 1 1 : 2
// 3: 1 1 1 / 1 2 / 3 : 3 (5개)
// 4 : 1 1 1 1 / 1 1 2 / 2 2 / 1 3 / 4 : 5 (8개)
// 5 : 1 1 1 1 1 / 1 1 1 2 (4개) / 1 2 2(3개) / 1 1 3 (3개) / 2 3 (2개) / 1 4 (2개) / 5 : 7 (16)
// 6 : 1 1 1 1 1 1 / 1 1 1 1 2 / 1 1 1 3 / 1 1 2 2 / 1 1 4 / 1 2 3 / 2 2 2 / 1 5 / 2 4 / 3 3 / 6 : 11

// 예시 3 10 / 1 2 5
// 1로 만들어 지는 경우 전부 진행 :dp[0] ~ dp[10] 전부 1로 바뀜
// 2로 만들 수 있는 수 : dp[2] += dp[0], dp[3] += dp[1] (1로 만드는 거에서 2를 더하면 3이기 떄문임)
// 위와 같이 진행되므로 점화식을 나타내면 dp[num] += dp[num - i] 이런식으로 나타낼 수있음
// 이를 for문으로 진행하여 문제를 해결하였다.

// 실행시간 : 0ms