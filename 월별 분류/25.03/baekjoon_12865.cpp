#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int dp[100001];
int check[101];
int ans = 0;

struct Data {
	int weight;
	int value;
};

vector<Data> v;

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int W, V;
		cin >> W >> V;
		v.push_back({ W, V });
	}
}

void cal() {
	for (int i = 0; i < N; i++) {
		int weight = v[i].weight;
		int value = v[i].value;

		for (int j = K; j >= weight; j--) {
			dp[j] = max(dp[j], dp[j - weight] + value);
		}

	}

	cout << dp[K] << "\n";
}

int main() {

	input();
	cal();


	return 0;
}

// 백준 12865번 : 평범한 베낭
// 냅색 문제 (베낭 문제)
// "최대 무게가 K인 배낭에 물건들을 넣어 최대 가치를 얻는 방법"을 구하는 문제이다.
// 생각해보면 각 물건은 다음과 같은 2가지 선택지를 가질 수 있다.
// 1. 넣는다. 2. 넣지 않는다.

// 그리고 냅색 또한 기본적으로 DP이다. 따라서, 뒤에서부터 계산하는 것이 중요하다.
// 점화식은 다음과 같다. dp[j] = max(dp[j], dp[j - weight] + value)
// dp[j - weight] : 물건을 넣고 남은 무게의 dp (최적화 무게) + value (넣었을 때의 가치)
// 이를 K부터 weight까지 계산하면 되는 것이다. 이를 모든 물건에 대해서 반복.
// 아래와 같은 예시가 있다고 해보자. 순서대로 weight value 이다.
// N= = 4, K = 7
//6 13
//4 8
//3 6
//5 12

//1. weight : 6, value : 13  dp[7] = max(dp[7], dp[7 - 6] + 13) = max(dp[7], dp[1] + 13) = 13 .... dp[6]까지 진행한다. (5이하는 남아 있는 무게가 5 이하가 될수가 없다.)
//2. weight : 4, value : 8  dp[4] = max(dp[7], dp[7 - 5] + 8) = max(13, dp[2] + 8) = 13 (기존값 유지) ... dp[4]까지 진행한다.
//등등 계속 진행하면 dp[7]에 모든 값이 쌓일 것이다.

// 실행시간 : 8ms